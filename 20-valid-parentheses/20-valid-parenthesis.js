/**
 * @param {string} s
 * @return {boolean}
 */
let solObj = {"[":"]", "(":")", "{":"}"}
class Stack{
    constructor(){
        this.items = [];
    }
    push(element)
    {
        // push element into the items
        this.items.push(element);
    }
    pop()
    {
        // return top most element in the stack
        // and removes it from the stack
        // Underflow if stack is empty
        if (this.items.length == 0)
            return "Underflow";
        return this.items.pop();

    }
    // peek function
    peek()
    {
        // return the top most element from the stack
        // but does'nt delete it.
        return this.items[this.items.length - 1];
    }
    // isEmpty function
    isEmpty()
    {
        // return true if stack is empty
        return this.items.length == 0;
    }
    printStack()
    {
        var str = "";
        for (var i = 0; i < this.items.length; i++)
            str += this.items[i] + " ";
        return str;
    }

}
var isValid = function(s) {
    var answer = false
   var stack = new Stack()
    problem = s.split("")
    console.log(problem)
    for(let i = 0 ; i<problem.length; i++){
        // console.log("stack",stack.printStack())
        // console.log("prob",problem[i], i )
// console.log("ansert", answer)        
        
        if (problem[i] =="(" ||problem[i]=="{" || problem[i] =="["){
            stack.push(problem[i])
            answer = false
        }
        else {
            if(problem[i] == solObj[stack.peek()]  ){
                // console.log(problem[i],"Top of the stack is ",stack.peek(),"SOlutio",solObj[stack.peek()], "ans", problem[i] == solObj[stack.peek()] )
                answer = true
                stack.pop()
            }   
            else{
                answer = false
                return answer
            }
                // console.log("problem[i] == solObj[stack.peek()] OP")
        }
    }
    // console.log("at last", answer, stack.printStack())
    if(stack.peek()){
        return false
    }
    return answer
};
