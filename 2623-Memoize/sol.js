/**
 * @param {Function} fn
 */
function memoize(fn) {
    // const cacheObject={};
    const cache = new Map();
    return function(...args) {
        const key = args.map(a=>typeof a + '|'+JSON.stringify(a)).join(',');
        if(cache.has(key)){
            return cache.get(key);
        }
    //   const key = JSON.stringify(args);
    //   if(key in args){
    //       return cacheObject[key];
    //   } 
      else{
          const result = fn(...args);
        //   cacheObject[key] = result;
        cache.set(key, result);
          return result;
      }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
