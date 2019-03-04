print("Sample Cosi Application")
print("(NOTE: default filename is 'main.js')")

function tick()
{
 return clock() / CLOCKS_PER_SEC
}

function wait(pause)
{
 var tock = tick() + pause;
 while(tick() < tock)
  continue
}

function print_mechanical(pace, text)
{
 srand(time(NULL))
 if(pace > 1)
  pace = 1 / pace
 function put_mechanical(byte)
 {
  var low = pace / 1728
  var modulated = 
   low + 
    (pace - low) * 
    (rand() / RAND_MAX)
  putchar(byte)
  fflush(stdout)
  wait(modulated) 
 } 
 var all = "";
 var args = arguments
 loop(
 { start: 1, end: args.length }, 
 function(idx)
 {
  all += args[idx]
 })
 var bytes = text_to_bytes(all) 
 loop(all, function(jdx)
 {
  put_mechanical(get_byte(bytes, jdx))
 })
 put_mechanical(0xa)
 free(bytes)
}

var text = file_to_text(script_path())
var args = argv_to_text_array()
if(!args.length)
 args = [1/5]
loop(args, function(idx)
{
 var pace = Number(args[idx])
 print("*** Script ***")
 print_mechanical(pace, text) 
})
