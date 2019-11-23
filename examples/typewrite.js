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

var args = script_arguments()
if(!args.length)
 args = [script_path()]
loop(args, function(idx)
{
 var arg = args[idx]
 var delay = rand() % 48, 
  text = file_to_text(arg) || file_to_text(arg + ".js")
 if(text)
  typewrite(delay, text)
 else
  typewrite(delay, "Error: cannot load file '", arg, "'") 
})
