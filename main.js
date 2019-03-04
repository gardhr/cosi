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
 function put_mechanical(byte)
 {
  var low = pace / 12
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
}

var text = file_to_text(script_path())
var args = argv_to_text_array()
if(!args.length)
 args = [1/6/12]
loop(args, function(idx)
{
 var pace = Number(args[idx])
 print("*** Pace: roughly", pace, "glyphs per second ***")
 print_mechanical(pace, text) 
})
