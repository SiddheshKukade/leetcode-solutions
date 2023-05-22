/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    // var ans = "{";
    // var length = Object.keys(object).length;
    // Object.keys(object).map((key,i) =>{ 
    //     console.log(ans, key, length);
    //     if(i+1 == length){
    //          ans+= `"${key}":${object[key]}`
    //     }else{
    //          ans+= `"${key}":${object[key]},`
    //     }
    //  }
    //  );
    // ans+=("}")
    // return ans;
    switch (typeof object) {
        case 'object':
            if(Array.isArray(object)){
                const elements = object.map((element)=>jsonStringify(element));
                return `[${elements.join(',')}]`;
            }else if(object){
const keys = Object.keys(object);
const keyValuePairs = keys.map(key=> `"${key}":${jsonStringify(object[key])}`);
return `{${keyValuePairs.join(',')}}`;
            }else return 'null';
        case `boolean`:
        case 'number':
            return `${object}`;
        case 'string':
            return `"${object}"`;
        default:
            return '';
    }
};
