/**
 * @param {any} o1
 * @param {any} o2
 * @return {boolean}
 */
var areDeeplyEqual = function(o1, o2) {
   if (typeof o1 !== typeof o2) {
    return false; // Return false if types are different
  }
     if (typeof o1 !== 'object' || o1 === null || o2 === null){
    return o1 === o2;
  }
  if(Array.isArray(o1) && Array.isArray(o2)){
      if(o1.length !== o2.length){
          return false;
      }
      //if array of objects is present.
      for(let i =0; i<o1.length; i++){
          if(!areDeeplyEqual(o1[i], o2[i])){
              return false;
          }
      }
      return true
  }
  // if one of them is array and other is not.
  if(Array.isArray(o1) || Array.isArray(o2)){
      return false;
  }
  const key1 = Object.keys(o1);
  const key2 = Object.keys(o2);
// if the length of the keys of objects are not matching
  if(key1.length !== key2.length){
      return false;
  }
  //checking that the keys of both objects are equal or not.
  for(const key of key1){
      if(!areDeeplyEqual(o1[key],o2[key])){
          return false;
      }
  }
  return true;
};
