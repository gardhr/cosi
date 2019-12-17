String.prototype.trimEnd = String.prototype.trimRight = function()
{
 var trm = this.trim();	
 var led = this.indexOf(trm);	
 return this.slice(0, trm.length + led);
}
print("/*", timestamp(), "*/")
var args = script_arguments()
for(var idx in args)
{
 var name = args[idx]
 var file = fopen(name, "r")
 if(file == NULL)
 {
  print("/* Error: could not read file '", name, "' */")
  continue
 }
 print("/*", name, "*/")
 while(true)
 {
  var input = read_line(file)
  if(input == null)
   break
  input = input.replace(/"/g, "\\\"")
  print("\"", input.trimEnd(), "\\n", "\"") 
 }
 fclose(file)
}