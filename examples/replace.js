function find_and_replace(text, find, replace, force)
{
 var sav = text, lst = sav
 while(true)
 {
  text = text.replace(find, replace)
  if(text == lst)
   break
  lst = text
 }
 if(!force)
 {
  var chk = find_and_replace(text, replace, find, true)
  if(chk != sav)
   return null
 }
 return text
}

function char(data)
{ 
 return data.charAt(0) 
}

function error(message)
{ 
 print("Error:", message) 
}

print("Find and Replace")
var file = prompt("File:")
var text = file_to_text(file)
if(!text)
 return error("cannot open file")
var temp = file + ".tmp"
if(!text_to_file(text, temp))
 return error("cannot create backup")
function cleanup(message)
{
 if(remove(temp) != 0)
  error("cannot delete backup file")
 else 
  return true
 return false
}
function bail(message)
{
 error(message)
 cleanup()
}
var find = prompt("Find:")
var replace = prompt("Replace:")
var choice = char(prompt("Force? [y/n]:"))
var force = tolower(choice) == char("y")
if(!force)
 print("Force:", choice ? "yes" : "no")
var result = find_and_replace(text, find, replace, force == "yes")
if(!result)
 return bail("procedure would be irreversible")
if(result == text)
 return bail("nothing to replace")
if(!text_to_file(result, file))
 return bail("file system write failed")
if(cleanup())
 print("Success!")
