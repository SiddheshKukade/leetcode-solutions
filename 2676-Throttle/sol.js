/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var throttle = function(fn, t) {
  let interval = null; // stores the ID of current intrval produced by setInterval()
  let qArgs = null; // storing the queue args
  const  processArgs= ()=>{ // processing the queue args if noting clear the intervals and move one
  ///if qArgs exists then call the function on them and  make it null;
      if(qArgs == null){ // if notinng previously 
          clearInterval(interval); // closes interval and exits the function.   
          interval = null; 
      }else{
          fn(...qArgs); // call with previous
          qArgs = null;
      }
  }
  return function(...args) {
if(interval){
    qArgs = args;
}else{ // nothing is being processed .
    fn(...args);
    interval = setInterval(processArgs, t);
}
  }
};

/**
 * const throttled = throttle(console.log, 100);
 * throttled("log"); // logged immediately.
 * throttled("log"); // logged at t=100ms.
 */
