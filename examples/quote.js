var args = script_arguments()
for(var idx in args)
{
 var file = fopen(args[idx], "r")
 if(file == NULL)
  continue
 while(true)
 {
  var input = read_line(file)
  if(input == null)
   break
  input = input.replace(/"/g, "\\\"")
  print("\"", input, "\\n", "\"", "\n") 
 }
 fclose(file)
}