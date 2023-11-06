# Object Orientated Programming

In the previous lab, we saw how classes can be used to encapsulate data and functions, such that complexity is hidden, and a programming interface is exposed that is both safer and easier to use.

One of the benefits of class types is that code can be more easily shared and reused.

One of the ways we saw class objects being reused was with **composition**, where members of a class we also class-types. As long as the public interface is sufficient, this is an often preferred way to re-use code.

In this section, we will look at another more subtle way to re-use code in a class, and that is through **inheritance**. This is a subject that can get complex very quickly, to the point that it might be viewed as counter-productive (I really don't want to start a flame war here). 

**Contents**

* [Object Orientated Programming](#object-orientated-programming)

   * [Object Inheritance](#object-inheritance)

   * [Overriding Behaviour](#overriding-behaviour)

   * [Operator Overloading](#operator-overloading) 

   * [Challenges](#challenges)

* [Advanced Topics](#advanced-topics)

   * [Copy Constructors](#copy-constructors)

   * [Polymorphism](#polymorphism)

   * [Pure Virtual Functions](#pure-virtual-functions)

      * [Example - Dependency Injection (DI)](#example---dependency-injection-di)

    * [Lambda Functions and Closures](#lambda-functions-and-closures)

    * [Smart Pointers](#smart-pointers)

    * [Advanced Challenges](#advanced-challenges)

---
   
## Object Inheritance

We begin this discussion with what object inheritance is not - it is not composition. Consider the following example:

```C++
class Dog {
    protected:
    string _name;
    int _age;

    public Dog(string name, int age) {
        _name = name;
        _age = age;
    }
    void bark() {
        cout << "Woof" << endl;
    }
};
```

The class `Dog` **has a** member called `name`, of type `string`. This is using composition. It reuses the code in `string` to make it easier to process string data. Access is limited to the public API of `string`.

Now consider the following class:

```C++
class Pet {
protected:
    string _name;
    int age_;

public:
    public Pet(string name, age) {
        _name = name;
        _age = age;
    }
};
```

This is more generic. It has some of the attributes of `Dog`, but nothing unique to `Dog` (cats also have names). This class models the generic properties of a pet (we might add more later).

We can now create two other *more specialist* classes which **inherit** the properties of `Pet`, and add some unique characteristics:

```C++
class Dog : public Pet 
{
public:
    public Dog(string name, int age) : Pet(name, age) {
    }
    void bark() {
        cout << name << " says Woof" << endl;
    }
}
```

The `Dog` class **inherits** all the properties of `Pet`, but **adds** the additional ability to make the sound *woof*. 

* The class declaration uses the `:` operator to designate any **parent class(es)**. 

```C++
   class Dog : public Pet
```

* The `Dog` class does not need to include a `name` property as it inherits it from `Pet`. 

* The `Dog` class is in effect **reusing** the properties and code in `Pet`, and adding additional functionality of it's own.

Similarly, cats are also pets. They differ from dogs in the sounds they make. We could therefore do something similar here:

```C++
class Cat : public Pet 
{
public:
    Cat(string name, int age) : Pet(name, age) {
    
    }

    void meow() {
        cout << name << " says Meow" << endl;
    }
}
```

Again, the `Cat` class **inherits** the all the properties of `Pet`, but adds the additional ability to make the sound *meow*.

**Important: the <u>is-a</u> relationship**

In the examples above, both `Cat` and `Dog` share a **parent class** `Pet`. They both inherit all the properties and functions of a `Pet`.

> Imagine you were playing a game of "guess what I am thinking of". The first question might be: "Does it have a name"?, to which the answer is "YES". The next question might be: "Does it have a biological age?", to which the answer is also "YES".
>
> With these two pieces of information, the player could equally say "It is a Cat", "It is a Dog" or "It is a Pet". At this stage, they are logically indistinguishable.

* A `Dog` inherits all the properties of `Pet`, so we can say that **`Dog` <u>is a</u> `Pet`**, as well as being a `Dog`
* A `Cat`  inherits all the properties of `Pet`, so we can say that **`Cat` <u>is a</u> `Pet`**, as well as being a `Cat`
* A `Pet` is NOT a dog, as it does not always `bark`. Equally is it is not a cat, as it does not always `meow`.




## Overriding Behaviour

## Operator Overloading

## Challenges

# Advanced Topics

## Copy Constructors

## Polymorphism

## Pure Virtual Functions

### Example - Dependency Injection (DI)

## Lambda Functions and Closures

## Smart Pointers

## Advanced Challenges

---

[Back to Table of Contents](./README.md)