function char(text)
{
 return text.charCodeAt(0)
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
  preset + 
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
 var copy = file + ".backup"
 if(!text_to_file(file_to_text(file), copy))
  print("Warning: cannot create backup of `" + file + "`")
 else 
  print("Note: made backup file `" + copy + "`")
}

print("Cosi Build Script")
var config = null
contain(function()
{
 config = file_to_object("config.js")
})
if(config == null)
{
 config = 
 {
  compile : "gcc -lm -o cosi cosi.c", 
  cosi: "cosi"
 }
}
var compile = config.compile = 
 aquire("Compile command", config.compile) 
var cosi = config.cosi = 
 aquire("Cosi", config.cosi)
if(confirm("Update config file with these settings?"))
 if(!object_to_file(config, "config.js"))
  print("Warning: cannot create `config.js`")
backup("cosi.txt")
backup("cosi_builtins.txt")
var quote = { js : cosi + " examples/quote" }
var commands = 
[
 compile, 
 quote.js + " cosi.js > cosi.txt", 
 quote.js + " cosi_builtins.js > cosi_builtins.txt"
]
print("The following commands will be invoked:\n")
for(var cdx in commands)
 print(commands[cdx])
if(!confirm("\nProceed?")) 
 return print("Aborting...")
for(var cdx in commands)
 system(commands[cdx])
print("Done!")