/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    var temp=n;
    return function() {
    return temp++;   
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */
