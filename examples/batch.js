var tag = "[batch]", ags = script_arguments()
if(ags.length == 0)
{
 return print
 (
  tag, 
  "Usage:", 
  script_path(), 
  "[file(s)...]"
 )
} 
for(var adx in ags)
{
 var fil = ags[adx]
 print(tag, "File:", fil)
 var txt = file_to_text(fil)
 if(txt == null)
 {
  print(tag, "Error: cannot open file")
  continue
 }
 var lst = txt.split("\n")
 for(var ldx in lst)
 {
  var cmd = lst[ldx].trim()
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
     res.toString() + 
     ") - bailing out!"
   )
  }
 }
 print(tag, "Done.")
}