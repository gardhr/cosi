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
var config = null
function aquire(key, message)
{
 function see(text)
 {  
  return empty(text) ? "undefined" : text
 }
 var preset = config[key]
 var result = prompt
 (
  message + 
  ": (default is " + 
  see(preset) + 
  ")\n>"
 ) || 
  preset
 print(message, "is", see(result))
 return config[key] = result
}
var format = 
{
 compile: "gcc -lm -o cosi cosi.c", 
 clean: "rm cosi",
 test: "./cosi",
 cosi_path: "", 
 bin_directory: "",
 interactive: true
}
function incompatible()
{
 for(var key in format)
  if(typeof(config[key]) === "undefined")
   return true
 return false
}
contain(function()
{ 
 config = file_to_object("config.js") 
})
if(config == null || incompatible())
 config = format
if(config.interactive)
{
 aquire("interactive", "Always in interactive mode") 
 aquire("cosi_path", "Path to cosi")
 aquire("bin_path", "System `bin` directory")
 aquire("clean", "Cleanup command") 
 aquire("compile", "Compile command") 
 aquire("Test", "Test command") 
 config.interactive = 
  (config.interactive === "false") 
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
print("Done.")