function absorb(get, set)
{
 set = set || {}
 if(get)
  for(var property in get)
   set[property] = get[property]
 return set
}

function procure(thing)
{
 var that = arguments
 return caught(function(){
  var len = that.length
  verify(len > 1)
  verify(thing)
  for(var idx = 1; idx < len; ++idx)
  {
   var 
    arg = that[idx],
    property = null,
    display = null 
   if(Array.isArray(arg))
   {
    property = arg[0]
    display = arg[1]
   }
   else
   {
    property = arg
    display = that[++idx]
   }
   if(!display)
    display = property
   display += ":"
   if(thing[property] == null)
    thing[property] = prompt(display)
  }
 }) ? false : true 
}

function procured(thing)
{
 var that = arguments
 return caught(function(){
  var len = that.length
  verify(len > 1)
  verify(thing)
  for(var idx = 1; idx < len; ++idx)
  {
   var 
    arg = that[idx],
    property = null
   if(Array.isArray(arg))
   {
    property = arg[0]
   }
   else
   {
    property = arg
   }
   verify(thing[property])
//...
  }
 }) ? false : true 
}


function find_and_replace(text, find, replace, unchecked)
{
 var result = null
 caught(function(){ 
  result = text.split(find).join(replace)
  if(!unchecked)
   if(result.split(replace).join(find) != text)
    result = null
 })
 return result
}

function file_find_and_replace(
 input, find, replace, output, unchecked)
{
 var result = null
 caught(function(){
  output = output || input
  result = text_to_file(
   find_and_replace(
    file_to_text(input), find, replace, unchecked),
   output) 
 })
 return result != null
}

function input_text_to_object()
{
 var 
  set = {},
  passed = false,
  that = arguments
 caught(function(){
  loop(that, function(idx){
   var 
    arg = that[idx]
   if(arg.search("=") >= 0 && arg.search(":") < 0)
    arg = find_and_replace(arg, "=", ":")
   var
    lit = "{" + arg + "}",
    get = text_to_object(lit)
   if(get == null)
    return
   absorb(get, set)
   passed = true
  })
 })
 return passed ? set : null
}

function to_text_array(argv, skip)
{
 var tab = []
 var align = sizeof('void*')
 var args = argv
 if(skip)
  args += align
 for(;;)
 {
  var ptr = get_memory(args)
  if(ptr == NULL)
   break
  tab.push(bytes_to_text(ptr))
  args += align
 }
 return tab
}

function text_array_to_magic(tab)
{
 var res = []
 caught(function(){
  if(tab instanceof Number || typeof(tab) === "number")
   tab = to_text_array(tab, true)
  var set = {}
  loop(tab, function(idx){
   var arg = tab[idx]
   res.push({ text : arg, object : input_text_to_object(arg) })
  }) 
 })
 return res.length ? res : null
}

function script_path()
{
 return bytes_to_text(get_memory(argv()))
}

function argv_to_text_array(skip)
{
 if(skip === undefined)
  skip = true
 return to_text_array(argv(), skip)
}
