function is_array(object)
{
 return Array.isArray(object)
}

function mixed_to_text_array(mixed)
{
 var ret = []
 var arr = is_array(mixed) ? mixed : [mixed]
 for(var adx in arr)
 {
  var nxt = arr[adx]
  if(is_array(nxt))
  {
   var tmp = mixed_to_text_array(nxt)
   for(var tdx in tmp)
    ret.push(tmp[tdx])
  }
  else
  {
   var str = nxt.toString()
   var lns = str.split("\n")
   for(var ldx in lns)
    ret.push(lns[ldx])
  }
 }
 return ret
}

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
 var lst = mixed_to_text_array(txt)
 for(var ldx in lst)
 {
  var cmd = lst[ldx]
  if(cmd == "")
   continue
  print(tag, "Run: `" + cmd + "`")
  var res = system(cmd)
  if(res != 0)
   return print
   (
    tag, 
    "Failed (status code: " + 
     res.toString() + ") - bailing out!"
   )
 }
 print(tag, "Done.")
}