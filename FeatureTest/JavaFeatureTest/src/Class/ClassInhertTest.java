package Class;

public class ClassInhertTest {
    public static class Employee {
        Double salary;
        String name = "Joe Doe";

        Employee(double salary) {
            this.salary = salary;
        }

        String getName() {
            return name;
        }

        Double getSalary() {
            return this.salary;
        }
    }

    public static class Manager extends Employee {
        Double bonus;

        Manager(double salary, double bonus) {
            super(salary);
            this.bonus = bonus;
        }

        Double getSalary() {
            return this.bonus + super.getSalary();
        }
    }

    public static void main(String[] args) {
        System.out.printf("Manager:%s\n", (new Manager(1000.0, 200.0)).getName());
        System.out.printf("Manager:%f\n", (new Manager(1000.0, 200.0)).getSalary());
        System.out.printf("Employee:%s\n", (new Employee(1000.0)).getName());
        System.out.printf("Employee:%f\n", (new Employee(1000.0)).getSalary());
    }
}