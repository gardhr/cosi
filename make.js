function char(text)
{
 return text.charCodeAt(0)
}

function empty(text)
{
 return text == null || text == ""
}

function object_to_file(object, file)
{
 var flg = false, dsc = "{"
 for(var key in object)
 {
  if(flg)
   dsc += ","
  else
   flg = true
  dsc += "\n"  
  var qot = "'", mem = object[key]
  if(typeof(mem) === "string")
   mem = qot + mem + qot
  dsc += " " + key + " : " + mem
 }
 dsc += "\n}"
 return text_to_file(dsc, file)
}

function aquire(message, preset)
{
 message += ": "
 var result = prompt(
  message + 
  "(default: " + 
  (empty(preset) ? "undefined" : preset) + 
  ")\n>") || 
  preset
 print(message, result)
 return result
}

function confirm(message)
{
 var yes = char("y"),  
  choice = tolower(char(prompt(message, "[y/n]\n>"))) 
 return choice == yes
}

function backup(file)
{
 var data = file_to_bytes({ file: file })
 if(data == null)
  return print("Warning: failed to read file", file) 
 var copy = file + ".backup",
  bytes = data.bytes, 
  length = data.length
 if(!bytes_to_file(bytes, copy, length))
  print("Warning: cannot create backup of `" + file + "`")
 else 
  print("Note: made backup file `" + copy + "`")
 free(bytes)
}

print("Cosi Build Script")
var format = 
{
 compile: "gcc -lm -o cosi cosi.c", 
 clean: "rm cosi",
 test: "./cosi",
 cosi_path: "", 
 bin_directory: "",
 interactive: true
}
var config = null
contain(function()
{
 config = file_to_object("config.js")
})
function incompatible()
{
 for(var key in format)
  if(typeof(config[key]) === "undefined")
   return true
 return false
}
if(config == null || incompatible())
 config = format
if(config.interactive)
{
 config.compile = 
  aquire("Compile command", config.compile) 
 config.cosi_path = 
  aquire("Path to cosi", config.cosi_path)
 config.bin_path = 
  aquire("System `bin` directory", config.bin_path)
 config.interactive = 
  aquire("Always in interactive mode", config.interactive) 
 if(confirm("Update config file with these settings?"))
  if(!object_to_file(config, "config.js"))
   print("Warning: cannot create `config.js`")
}
backup("cosi.txt")
backup("cosi_builtins.txt")
var prefix = config.cosi_path
if(!empty(prefix))
 prefix += "/"
var quote_js = prefix + "cosi examples/quote ",
 backup_builtins = quote_js + 
  "cosi_builtins.js > cosi_builtins.txt",
 backup_interpreter = quote_js + 
  "cosi.js > cosi.txt",
 commands = 
[
 config.clean,
 backup_builtins,
 backup_interpreter,
 config.compile,
 config.test
]
print("The following commands will be invoked:\n")
for(var cdx = 0; cdx < commands.length; ++cdx)
 if(!empty(commands[cdx]))
  print(commands[cdx])
if(!confirm("\nProceed?")) 
 return print("Aborting...")
for(var cdx = 0; cdx < commands.length; ++cdx)
 if(!empty(commands[cdx]))
  system(commands[cdx])
var cbd = config.bin_path
if(!empty(cbd))
 backup(cbd + "/cosi")
print("Done!")