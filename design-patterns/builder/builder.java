class Person {
    private String name;
    private String lastName;
    private int age;

    public Person (String name, String lastName, int age) {
        this.name = name;
        this.lastName = lastName;
        this.age = age;
    }

    public String toString() {
        return String.format("%s %s: %d years old", this.name, this.lastName, this.age);
    }
}

class PersonBuilder {
    private String name;
    private String lastName;
    private int age;

    public PersonBuilder withName(String name) {
        this.name = name;
        return this;
    }

    public PersonBuilder withLastName(String lastName) {
        this.lastName = lastName;
        return this;
    }

    public PersonBuilder withAge(int age) {
        this.age = age;
        return this;
    }

    public Person build() {
        return new Person(this.name, this.lastName, this.age);
    }
}

class Main {
    public static void main(String[] args) {
        Person person = new PersonBuilder()
            .withName("Nina")
            .withLastName("Garcia")
            .withAge(5)
            .build();

        System.out.println(person);
    }
}
