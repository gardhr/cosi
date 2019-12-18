var tag = "[batch]"
var ags = script_arguments()
for(var adx in ags)
{
 var file = ags[adx]
 print(tag, "File:", file)
 var txt = file_to_text(file)
 if(txt == null)
 {
  print(tag, "Error: cannot open file")
  continue
 }
 var lst = txt.split("\n")
 for(var ldx in lst)
 {
  var cmd = lst[ldx]
  if(cmd == "")
   continue
  print(tag, "Run: `" + cmd + "`")
  var res = system(cmd)
  if(res != 0)
  {
   return print
   (
    tag, 
    "Failed (status code: " + 
     res.toString() + ") - bailing out!"
   )
  }
 }
 print(tag, "Done.")
}