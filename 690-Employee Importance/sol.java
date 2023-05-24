/// SIMPLE DFS and recursion

/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    private int getImportance(Map<Integer, Employee> employees, int id){
        if(!employees.containsKey(id)){
            return 0;
        }
        Employee employee = employees.get(id);
        int totalValue=employee.importance;

        for(int report: employee.subordinates){
            totalValue += getImportance(employees, report);
        }
        return totalValue;

    }
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> employeeMap = new HashMap<>();

        for(Employee employee: employees){
            employeeMap.put(employee.id, employee);
        }

        return getImportance(employeeMap, id);
    }
}
