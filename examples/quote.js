function read_line(stream)
{
 if(!stream)
  stream = stdin
 var newline = 0xa,
  res = "",
  max = 32, 
  siz = max + 1, 
  buf = read_line.buf
 if(!buf)
  buf = read_line.buf = malloc(siz)
 while(true)
 {
  if(!fgets(buf, siz, stream))
   return res.length == 0 ? null : res
  var len = strlen(buf), lst = len ? len - 1 : 0 
  if(get_byte(buf, lst) == newline)
   set_byte(buf, len = lst, 0)
  res += bytes_to_text(buf)
  if(len != max)
   return res
 }
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
  print("\"", input, "\\n", "\"") 
 }
 fclose(file)
}