print("/*", timestamp(), "*/")
var args = script_arguments()
for(var idx in args)
{
 var name = args[idx]
 var file = fopen(name, "r")
 if(file == NULL)
  continue
 print("/*", name, "*/")
 while(true)
 {
  var input = read_line(file)
  if(input == null)
   break
  input = input.replace(/"/g, "\\\"")
  print("\"", input, "\\n", "\"") 
 }
 fclose(file)
}