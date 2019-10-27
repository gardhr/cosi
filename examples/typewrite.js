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

function typewrite(pace, text)
{
 function typebyte(byte)
 {
  var modulated = pace * (rand() / RAND_MAX)
  putchar(byte)
  fflush(stdout)
  wait(modulated) 
 } 
 if(pace > 1)
  pace = 1 / pace
 var combined = "";
 for(var idx = 1; idx < arguments.length; ++idx)
  combined += arguments[idx]
 var bytes = text_to_bytes(combined) 
 loop(combined, function(idx)
 {
  typebyte(get_byte(bytes, idx))
 })
 typebyte(0xa)
 free(bytes)
}

function pick()
{
 return 1 / (rand() % 24)
}

function show()
{
 [].unshift.call(arguments, pick())
 typewrite.apply(null, arguments) 
}

/*
  Typewrite yourself!  
*/

show("~ Self Typing Typewriter ~")
srand(time(NULL))
var args = script_arguments()
if(!args.length)
 args = [pick()]
var text = file_to_text(script_path())
loop(args, function(idx)
{
 var pace = Number(args[idx])
 show("*** Script (printed with ", pace, " second delays) ***")
 typewrite(pace, text) 
})
show("Done!")
