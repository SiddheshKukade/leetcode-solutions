class Solution {
    public int numRescueBoats(int[] people, int limit) {
        //limit is max capacity of the boat
        //fit the proper people in proper boat
        //return the minimum number of boat

        //hint 
        //EVERYONE CAN BE CARRIED BY THE BOAT AND EVERYONE CAN BE SAVED.    

        //sol
        //add heaviest then try to add lightest if possible
        //if not only add heaviest and keep repeating
        Arrays.sort(people);
        int numBoats=0;
        int i=0;
        int j=people.length-1; // count of total people
        while(i<=j){ // track of how many people saved
            if(people[i] + people[j] <= limit){  // if we can carry both
            i++; // reducing for both the persons with i++ and j--
            j--;
            }
            else{ // only reduced for one person
                j--;
            }
            numBoats++; // boats counted anyway
        }
        return numBoats;
    }
}
