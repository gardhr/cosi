var config = null, 
 format = 
 {
  compile: "gcc -lm -o cosi cosi.c", 
  clean: "",
  test: "./cosi",
  cosi_path: "", 
  bin_path: ""
 }

function char(text)
{
 return text.charCodeAt(0)
}

function empty(text)
{
 return text == null || text == ""
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
 if(!data)
  return print("Warning: failed to read file", file) 
 var copy = "backup." + file,
  bytes = data.bytes, 
  length = data.length
 if(!bytes_to_file(bytes, copy, length))
  print("Warning: cannot create backup of `" + file + "`")
 else 
  print("Note: made backup file `" + copy + "`") 
 free(bytes)
}

function update()
{
 if(!text_to_file(JSON.stringify(config, null, "\n"), "config.js"))
  print("Warning: cannot update `config.js`")
}

function aquire(key, message)
{
 function see(text)
 {  
  return empty(text) ? "not set" : text
 }
 var preset = config[key]
 var result = prompt
 (
  message + 
  ": (default is " + 
  see(preset) + 
  ")\n>"
 )
 || 
  preset
 print(message, "is", see(result))
 return config[key] = result
}

function incompatible(object, control)
{
 for(var key in control)
  if(typeof(object[key]) === "undefined")
   return true
 return false
}

print("Cosi Build Script")
config = file_to_object("config.js") 
if(config == null || 
 incompatible(config, format))
{
 print("Fixing invalid configuration...")
 config = format
 update()
}
if(confirm("Enter interactive mode?"))
{
 aquire("cosi_path", "Path to cosi")
 aquire("bin_path", "System `bin` directory")
 aquire("clean", "Cleanup command") 
 aquire("compile", "Compile command") 
 aquire("test", "Test command") 
 if(confirm("Update config file with these settings?"))
  update()
}
backup("cosi.txt")
backup("builtins.txt")
var prefix = config.cosi_path
if(!empty(prefix))
 prefix += "/"
var quote_js = prefix + "cosi examples/quote ",
 imbed_builtins = quote_js + 
  "builtins.js > builtins.txt",
 imbed_interpreter = quote_js + 
  "cosi.js > cosi.txt",
 commands = 
 [
  config.clean,
  imbed_builtins,
  imbed_interpreter,
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
var cbp = config.bin_path
if(!empty(cbp))
 backup(cbp + "/cosi")
print("Done.")
