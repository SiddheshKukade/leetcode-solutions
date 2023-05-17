/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let ans = [];
    for(var i=0; i<arr.length;i++){
        ans[i] = fn(arr[i],i);
    }
    //   ans.push(fn(ar));
    // });
    console.log(ans);
    return ans;
};
