srand(time(NULL))

function typewrite(delay, text)
{ 
 function tick()
 {
  return clock() / CLOCKS_PER_SEC
 }
 function wait(delay)
 { 
  var later = tick() + delay
  while(tick() < later)
   continue
 }
 function typebyte(byte)
 {
  var modulated = delay * (rand() / RAND_MAX)
  putchar(byte)
  fflush(stdout)
  wait(modulated) 
 }
 if(delay > 1)
  delay = 1 / delay
 var combined = "";
 for(var adx = 1; adx < arguments.length; ++adx)
  combined += arguments[adx]
 var bytes = text_to_bytes(combined) 
 loop(combined, function(idx)
 {
  typebyte(get_byte(bytes, idx))
 })
 typebyte(0xa)
 free(bytes)
}

/*
  Typewrite!  
*/

var args = script_arguments(),
 length = args.length
if(length == 0)
 args = [script_path()]
if(length < 2)
 args.push(3) 
var file = args[0],
 pause = args[1] | 0, 
 text = file_to_text(file) || 
  file_to_text(file + ".js")
if(text)
 typewrite(pause, text)
else
 typewrite(pause, 
  "Error: cannot load file '", file, "'")