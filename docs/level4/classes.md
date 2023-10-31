# Classes

In this session, we will look at a very important language feature of C++, that is creating and using **class types**.

**Contents**

* [Pointers and References](#pointers-and-references)
   1. [Pass by Value and Pass by Reference](#pass-by-value-and-pass-by-reference)
* [Fundamentals of Classes](#fundamentals-of-classes)
   1. [Simple class type](#simple-class-type)
   1. Constructor
   1. Initialiser Lists
   1. Destructors 
   1. Overloading
* Encapsulation
   1. Public and Private members
   1. Create an API
* Composition
   1. Objects as members
   1. Initialisation of objects 
* Instantiating
   1. Static Instantiation
   1. Dynamic Instantiation
   1. References vs Pointers
* Templates
   1. Type parameters
   1. Non-typed Parameters 
* Statics
   1. Members
   1. Functions

* Challenges

## Pointers and References

Before we embark on our exploration of classes, it would probably benefit the reader to take a closer look at two important concepts in C+, *pointers* and *references*.

> Pointers tend only to feature in C and C++. They are a very low level construct commonly used by system engineers to manipulate memory directly
>
> References are an *abstraction* of pointers, and tend to feature in most imperative languages (such as C# and Java)
>
> To really understand references in C++ (and other languages), it helps to understand pointers.

| Task 01 | 01-PointersAndReferences |
| - | - |
| 1 | Open the solution file Classes in Visual Studio 2022 |
| 2 | Make `01-PointersAndReferences` the start up project |
| 3 | Step each line, reading the comments. Pause to predict the output when prompted in the comments |

**Key Points**

[Watch this debriefing video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=a8f11e2d-34aa-4129-8568-b0ac00e9887f) to review the main points. 

* A pointer type is just a variable that holds an address of some data in memory
   * You read and write to the memory by *de-referencing* with the \* operator
* A reference type is a variable that shares the same address with another variable
   * If you change one, you change the other

### Pass by Value and Pass by Reference

Pointers and references are commonly used to allow functions to directly modify data.

| Task | 03-PassByValueAndReference |
| - | - |
| 1. | Make `03-PassByValueAndReference` the start up program |
| 2. | Step each line, reading the comments. Pause to predict the output when prompted in the comments |

**Key Points**

In this task, we first observe passing a parameter by value:

```C++
    // Create and initialise a
    int a = 100;

    // (a) - by value - will a be affected?
    int b = addOneByValue(a);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
```

In this case, the **value** of `a` is **copied** into the parameter `u`. At this point, `a` and `u` are entirely independent variables.

```C++
int addOneByValue(int u) {
    u = u + 1;
    return u;
}
```
As a consequence, `a` is unaffected. Constrast this with the next example:

```C++
    // (b) - by pointer - will a be affected?
    addOneByPointer(&a);
    cout << "a = " << a << endl;
```

Note how the **address** of `a` (`&a`) is copied into the parameter `pointerToU`.

```C++
void addOneByPointer(int* pointerToU) {
    *pointerToU = *pointerToU + 1;
}
```

This function then reads the value at address `pointerToU` using the re-referencing operator `*`. 

> `*pointerToU` can be thought of as "read the value at address `pointerToU``

The read value has `1` added, and the resulting *value* is copied into the memory at address `pointerToU` again using the de-referencing operator `*`.

> Note that `pointerToU = *pointerToU + 1;` would be incorrect. This would change the stored address to `101`. I've no idea what you would find at address `101`!

Finally, we can achieve the same thing with much nicer syntax by using C++ *reference types*.

```C++
    // (c) - by reference - will a be affected?
    addOneByReference(a);
    cout << "a = " << a << endl;
```

The way to interpret this is that the parameter `refToU` will hold the same address as the variable passed to it (in this case `a`).

```C++
void addOneByReference(int& refToU) {
    refToU = refToU + 1;
}
```

Therefore, by modifying `refToU`, you must also modify `a`.

Do not think this is just a `C++` feature. Most languages have reference types. Under the hood are pointers, but they are purposely hidden from view.

## Fundamentals of Classes

Most of the code we have seen uses the *baked in* data types, including `char, short, int, long, float, double`.

We have also **used** other types, including `string`, `ofstream` and `ifstream`. We use these **custom data types** to create a special type of variable we call an **object**. 

We saw how *objects* can contain data, but also functions. For example:

```C++
string name = "The module is COMP1000";
size_t loc = name.find("module");
```

Note how object `name` (type `string`) contains data, and the function `find()` which searches that data. 

* The details of data storage and function code are **encapsulated** inside, hiding the complexity, and making the object easy and safe to use. 

* In contrast to using pure C strings, it is much easier to embed complex string processing capabilities within our own applications. Each time we use a `string`, we are effectively **reusing** code written (and tested) by others.

> Encapsulation and reuse are two core features of a very important programming paradigm, that is **Object Orientated Programming**, or **OOP**.

In this section, we will learn to **create our own custom data types** using the `class` keyword. In the next lab, we will look at some more advanced object orientated concepts.

### Simple class type

A class in it's most basic form is similar to a C structure. Consider the following structure:

```C++
struct Rect {
    float width;
    float height;
    double area;
}
```

We have now created a custom data type `Rect`. In this example it has three members: `width`, `height` and `area`. We can read and write those members. For example:

```C++
Rect r1 = {2.0, 3.0, 0.0};
r1.area = r1.width * r1.height;
```

Earlier in the course we saw how we might write functions to manipulate the members. For example:

```C++
void updateArea(Rect* this) {
    //Pointers use -> arrow notation, as opposed to . dot
    this->area = this->width * this->height;
}
```

Note how the parameter `this` is a **pointer** (address). Having access to the address of a variable means the function can overwrite that data at that address. We say that it can perform *in-place modification*. You might now do the following:

```C++
Rect r1 = {2.0, 3.0, 0.0};  //Create and initialise
updateArea(&r1);            //Pass the ADDRESS of the data
cout << r1.area << endl;    //Output is 6.0
```

**Deep down, a class is similar to a structure, only the `this` parameter is automatically provided.**

As discussed previously, the arrow-notation can be visually distracting. You can also use a C++ reference instead of a pointer.

```C++
void updateArea(Rect& ref) {
    ref.area = ref.width * ref.height;
}
```

Note how the dot-notation is used. When we invoke this, we might now do the following:

```C++
Rect r1 = {2.0, 3.0, 0.0};  //Create and initialise
updateArea(r1);             //Pass a REFERENCE of the data
cout << r1.area << endl;    //Output is 6.0
```

This works because **the parameter `ref` is a reference type, so has the same address as `r1`**.  

> An argument against this is that it is less clear from the code that `updateArea` performs in-place modification. You would simply have to "know". 

Let's now build on this example. In the next task, you will witness a class and a structure that perform the same task.

| TASK | 05-RectClass |
| - | - |
| 1. | Make 05-RectClass the start up project |
| 2. | Step through the code to see what it does |
| - | Use the step-in feature of the debugger to step into the functions. Read the comments |
| - | Note the location of each function your encounter |

There is a LOT to take in here, so let's break this down. First, let's look at the structure.

```C++
//Using C structures
Rect_t r1 = CreateRect(2.0, 3.0);
display(r1);
setHeight(r1, 10.0f);
display(r1);
```

This worked well as long as we only use the API. However, we can easily break it.

| TASK |  |
| - | - |
| 3. | Change the code above to read as follows |
| - | Build and run - notice how the area is not updated! |

```C++
//Using C structures
Rect_t r1 = CreateRect(2.0, 3.0);
display(r1);
//setHeight(r1, 10.0f);
 r1.height = 10.0;
display(r1);
```

The compiler cannot stop us doing this with structures. However, with a class it can.
Now let's look at the version with a class:

```C++
//Using C++ class
Rect r2(2.0, 3.0);
r2.display();
r2.setHeight(10.0f);
r2.display();
```

| TASK |  |
| - | - |
| 4. | Change the code above to read as follows |
| - | Try and build the code - Note any errors |

```C++
//Using C++ class
Rect r2(2.0, 3.0);
r2.display();
//r2.setHeight(10.0f);
r2.height = 10.0;
r2.display();
```

You probably got an error message similar to:

`'Rect::height': cannot access private member declared in class 'Rect'`

This error occurs because the member variable `height` cannot be accessed outside of the class. This rule is enforced by the **compiler**. To understand how this is done, we now need to look at the class declaration.

```C++
class Rect
{
//Private section - only class Rect member functions can access these
private:
    float width;
    float height;
    double area;

    void updateArea() {
        area = width * height;
    }

public:
    //Constructor - always called when a new object is created
    Rect(float w, float h) {
        this->width = w;        //We can use the this pointer
        height = h;             //Or infer it
        updateArea();
    }

    //Setter
    void setHeight(float h) {
        if (height != h) {
            height = h;
            updateArea();
        }
    }

    //Getter
    double getArea() {
        return area;
    }

    //Display utility function
    void display() {
        std::cout << "Width: " << width << ", Height: " << height << ", Area: " << area << std::endl;
    }

};
```

The **members** of this class are in an area labelled **private:**

```C++
private:
    float width;
    float height;
    double area;
    ...
```

Nothing the **private** section can be accessed from outside of the class. So back in main, the following line will not compile:

```C++
r2.height = 10.0;   //Will not work - height is private
```

A class does not just contain member data. It also contains **member functions**. These functions are part of the class, and **do** have access to the private section(s).

For example:

```C++
void setHeight(float h) {
    if (height != h) {
        height = h;
        updateArea();
    }
}
```

Note how this function is able to directly read and modify `height`? This is because `setHeight` is a **class member function of `Rect`**.

The member functions in this class include:

* `updateArea` - this is a private member function, so can only be called from another class member function.
* `display` - used to write information to the terminal
* `setHeight` - a "setter function", used to set the value of the `height` member variable (and then update the area)
* `getArea` - a "getter" function that returns a **copy** of the area member variable
* `Rect` - a special function known as a **constructor**. This will be discussed next.

All these member functions have access to all member variables and member functions in the class.

### Constructor

There is a very special and important member function called a constructor. A  constructor function has the following unique properties:

* It has the same name as the class
* It has no return type

When we created a new **instance** of our class in main, it was done as follows:

```C++
Rect r2(2.0, 3.0);
```

> **Terminology**
>
> We say that `r2` is an **instance of** `Rect`. We also say `r2` is an **object**.

When this line runs, two things happen:

* Memory is allocated for a new object (to store members `height`, `width` and `area` )
* The **constructor** function is then run and given the opportunity to initialise the member variables.

The constructor function is shown below:

```C++
//Constructor - always called when a new object is created
Rect(float w, float h) {
    this->width = w;        //We can use the this pointer
    height = h;             //Or infer it
    updateArea();
}
```

In this example, two methods of writing to the member variables are shown. The address of `r2` is will stored in the pointer variable `this`. We can use this pointer to change any member variable:

```C++
this->width = w;
```

If you drop the `this->` part, the compiler will infer it. So the following line:

```C++
height = h; 
```

is really 

```C++
this->height = h; 
```

> Having the compiler infer `this->` keeps the code less cluttered. Some consider it bad practise however.

The **private** `updateArea()` member function is then called from within the constructor:

```C++
 void updateArea() {
     area = width * height;
 }
```

Again, by implication, this is equivalent to:

```C++
void updateArea() {
    this->area = this->width * this->height;
}
```

This is allowed as the constructor function is a member of the class, so can access anything in the `private` section.

> You cannot call `updateArea()` from outside the class however because it is `private`.

#### Setters and Getters

The member variable `area` is not accessible from outside the class. However, **read only** access can be provided by using a *getter function*

```C++
double getArea() {
    return area;
}
```

This function returns a **copy** of the current value of `area`. In main, we could use this as follows:

```C++
Rect r2(2.0f, 3.0f);
double a = r2.getArea();
```

Note that `a` and the internal `area` are entirely independent. We also can allow properties to be set using a **setter function**, such as the member function, `setHeight`:

```C++
void setHeight(float h) {
    if (height != h) {
        height = h;
        updateArea();
    }
}
```

Once again we infer `this->`. You might use it as follows: 

```C++
Rect r2(2.0f, 3.0f);
r2.setHeight(5.0f);
```

As `setHeight` is a public function, so it can be called from anywhere. This is called a *setter* as it is used to set a member variable. Of course, all the necessary house keeping is performed as well (updating the area in this case).

| TASK |  |
| - | - |
| 5. | The setter function for `width` is missing.  |
| - | Add another member function to the class to implement this |
| - | A solution is provided |

### Initialiser Lists

If we look at the constructor, we will see both `width` and `height` being initialised within the code body:

```C++
Rect(float w, float h) {
    this->width = w;        //We can use the this pointer
    height = h;             //Or infer it
    updateArea();
}
```

Another way to write this is with an **initialiser list** as follows:

```C++
Rect(float w, float h) : width(w), height(h) {
    //Code body
    updateArea();
}
```

The difference is subtle. 

* The `width` property is first initialised to `w`
* The `height` property is then initialised to `h`
* THEN the constructor code body is entered

In summary, initialisation lists are performed **before** the constructor runs. The significance of this will become apparent later.

### Destructors

We've met the constructor function, which is called when ever an object is created. We can also create a destructor that runs when ever an object is destroyed. To illustrate this, let's expand out `Rect` class to include some file handling.

# DO NOT READ PAST THIS POINT

### Overloading



## Encapsulation

### Public and Private members

### Create an API



## Instantiating
  
### Static Instantiation

### Dynamic Instantiation

### References vs Pointers


### Objects as members

### Initialisation of objects 




## Templates

### Type parameters

### Non-typed Parameters 



## Statics

### Members

### Functions





# Challenges