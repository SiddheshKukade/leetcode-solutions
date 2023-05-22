/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        let ans = x;
        // for(var i =0; i<functions.length-1; i++){
        //   ans =   functions[i](functions[i+1]);
        // }
        functions = functions.reverse();
        console.log(functions);
         functions.map(fn => {
             ans= fn(ans)
         });
        return ans;

    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */
