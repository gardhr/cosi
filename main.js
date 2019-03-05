
print("Sample Cosi Application")
print("(NOTE: default filename is 'main.js')")

function tick()
{
 return clock() / CLOCKS_PER_SEC
}

function wait(delay)
{
 var rest = tick() + delay
 while(tick() < rest)
  continue
}

function print_mechanical(pace, text)
{
 srand(time(NULL))
 if(pace > 1)
  pace = 1 / pace

 function put_mechanical(byte)
 {
  var modulated = pace * (rand() / RAND_MAX)
  putchar(byte)
  fflush(stdout)
  wait(modulated) 
 }
 
 var combined = "";
 for(var idx = 1; idx < arguments.length; ++idx)
  combined += arguments[idx]
 var bytes = text_to_bytes(combined) 
 loop(combined, function(idx)
 {
  put_mechanical(get_byte(bytes, idx))
 })
 put_mechanical(0xa)
 free(bytes)
}

var args = argv_to_text_array()
if(!args.length)
 args = [1/4]
var text = file_to_text(script_path())
loop(args, function(idx)
{
 var pace = Number(args[idx])
 print("*** Script (printed with", pace, "second delays) ***")
 print_mechanical(pace, text) 
})
