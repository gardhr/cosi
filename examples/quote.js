var args = script_arguments()
for(var idx in args)
{
 var file = fopen(args[idx], "r")
 if(file == NULL)
  continue
 while(true)
 {
  var line = read_line(file)
  if(line == null)
   break
  line = line.replace(/"/g, "\\\"")
  prints("\"", line, "\\n", "\"" ) 
 }
 fclose(file)
}