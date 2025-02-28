# Design Patterns

!! The code in these folders were initially done during an online course and contain a lot of unnecessary comments or notes that should not be present in a final code.

## Table of Contents

1. [Introduction](#introduction)
2. [Types](#types-gamma-categorization)
3. [Patterns](#patterns)
  i. [Builder](#builder)
  ii. [Factory](#factory)
  iii. [Prototype](#prototype)
  iv. [Singleton](#singleton)
  v. [Adapter](#adapter)
  vi. [Bridge](#bridge)
  vii. [Composite](#composite)
  viii. [Bridge](#bridge)

## Introduction

Design Patterns

## Types (Gamma Categorization)

- Creational
Creation/Construction of objects
  - Builder
  Provides an API for constructing an object step-by-step
  - Abstract Factory and Factory Method
  Component responsible solely for the wholesale (not piecewise) creation of objects.
  - Prototype
  A partially or fully initialized object that you copy (clone) and make use of.
  - Singleton

- Structural
Concerned with structure (e.g. class members)
  - Adapter
  - Bridge
  - Composite
  - Decorator
  - Facade
  - Flyweight
  - Proxy

- Behavioural
  - Chain of Responsibility
  - Command
  - Interpreter
  - Iterator
  - Mediator
  - Memento
  - Observer
  - State
  - Strategy
  - Template Method
  - Visitor

### OOP Notion Recap

#### abstraction

concept of hiding the complex behaviour by making it appear "easy"

#### encapsulation

controlled public interfaces giving access to private data (such as use of mutators/setters and accessors/getters to modify and access variables respectively; also makes good use of constructors for initialisation)

#### inheritance

derived classes inheriting properties from their parent class

#### polymorphism

treat multiple different objects as their base object type

## Patterns

### Builder

A builder is a separte component for building a particular object.

Builder

- can have a constructor and act as a standalone component and needs instantiation, or
- return itself via a static function making it more fluent

Different independent parts of an object can be built using different builders working together inheriting from the same base class

### Factory

Component responsible solely for the wholesale (not piecewise) creation of objects.

- Static method that creates objects
- Takes care of object creation (entirely)
- Can be external or reside inside the object as an inner class
- Hierarchies of factories can be used to create related objects

Uses a method or member function to initialize the object

Motivation :
Object creation logic becomes too convoluted

Constructor is not descriptive (name = name of type + no overloading w/ same arguments set w/ different names)
Constructor gets messy with optional parameters w/ too many parameters

Factory = lots of variety ; Builder = piece by piece object definition

non-piecewise object creation:

- Factory Method : separate function
- Factory : separate class
- can create hierarchy of factories with Abstract Factory

Factory Method is part of Gang of Four

Abstract Factory
Family of Factories
Uses inheritance to polymorphically call on the different factories

### Prototype

A partially or fully initialized object that you copy (clone) and/or customise before making use of.

About object copying for customisation
Use: When it’s easier to copy an existing object to fully initialize a new one

Complicated objects (e.g. cars) aren’t designed from scratch each time, design is iterative. Existing designs are reiterated on to make newer designs. Similarly, a Prototype exists to provide a base.

Prototype

- provides an existing base design (can even be initialized using a Builder)
- can be partially or fully constructed
- General idea is that variations are made following a clone/copy of the Prototype
  - This requires ‘deep copy’ support
    ‘Deep copy’ => copy objects as well as references while replicating the state of the references
    -> This allows the copied object and the prototype to be fully independent from each other
  - another way is to serailize and deserialize (boost)
- Cloning can (should?) be made convenient using a Factory

### Singleton

A component which is instantiated only once.

For some components it only makes sense to have one in the system.

Least loved Pattern.

Sometimes only one instance of a component is enough. Sometimes the constructor call is costly so you only want to do it once and provide everyone with the same instance.

For example

- a database manager may only need to load a database once into memory at the start and then only has to reply to requests with data in the database.
- an object factory which only needs 1 instanciation to allow a user to create objects afterwards.

Another reason to have a singleton is to prevent users from having a copy of the object. Or you want to avoid the risk of having a specific object instantiated more than once when dealing with multiple threads.

One problem that can arise with the Singleton is that a class tightly coupled with the Singleton can have tests associated that are testing the functioning of the Singleton it calls and not of the class itself. This can be mitigated using dependency injection. In short, hard dependance on a Singleton should be avoided, use dependency injection to make it possible for tests to use a Test Database on which the tester has total control.

To make a "safe" singleton, hide or delete the type's constructor, copy constructor, and copy assignment operator; create a static method that returns a reference to a static member
Note: This type of implementation is thread-safe as from C++11

Note: Types with closely coupled dependencies on singletons are more difficult to unit test. This is why direct dependency is not a good idea, and it's recommended to go via Dependency Injection to allow to decouple the singleton and provide a fake object for testing

To see also how to define a singleton lifetime in a dependency injection (DI) container

#### Monostate

#### Multiton

Singleton = only 1 instance possible
Multiton = key map with restricted number of elements to allow a fixed number of instances

### Adapter

A construct which adapts an existing interface X to conform to the required interface Y

Getting the interface you want from the interface you have

Careful as intermediate representations such as caches or other optimisations can pile up.

### Bridge

A mechanism that decouples an interface (hierarchy) from a implementation (hierarchy)

Connecting components together through abstractions

Bridge prevents a 'Cartesian product' complexity explosion

Example:

- Base class `ThreadScheduler`
- Can be preemptive or cooperative
- Can run on Windows or Unix
- End up with a 2x2 scenario: `WindowsPTS`, `UnixPTS`, `WindowsCTS`, `UnixCTS`

Bridge pattern avoids the entity explosion

Without Bridge, we have 4 distinct classes:

```text
ThreadScheduler
^
├── PreemptiveThreadScheduler
│   ^
│   ├── WindowsPTS
│   ├── UnixPTS
├── CooperativeThreadScheduler
│   ^
│   ├── WindowsPTS
│   ├── UnixCTS
```

With Bridge

```text
ThreadScheduler ──────────────────> IPlatformScheduler
-platformScheduler                      ^
^                                       |
├── PreemptiveThreadScheduler           ├── UnixScheduler
├── CooperativeThreadScheduler          ├── WindowsScheduler
```

Depends on a platformScheduler that acts as an interface whether it's Linux or Windows Scheduler and inherits from either Preemptive or Cooperative Thread Scheduler. This ensures Loose coupling.

#### Pimpl Idiom

The Pimpl (Pointer to IMPLementation) idiom is a design pattern in C++ used to hide implementation details from the header file, reducing compilation dependencies and improving encapsulation. It is a form of information hiding that helps achieve better modularity and faster compilation times.

Instead of defining all implementation details in the class definition, the class contains only a forward-declared pointer to an implementation (Impl class), which is defined in the .cpp file.

**Benefits:**

- Better Encapsulation: Hides implementation details from clients.
- Reduced Compile-Time Dependencies: Changes in the implementation do not require recompiling the dependent code.
- Binary Compatibility: Changes to the private implementation do not affect the public interface.
- Stable ABI: Useful in libraries where changes to headers should not break client code.

**Comparison with the Bridge Pattern**
Pimpl is purely about compilation boundaries and implementation hiding.
Bridge separates abstraction from implementation, often for flexibility in object-oriented designs.

### Composite

Treating individual and aggregate objects in the same manner

Structural pattern used to treat individual (scalar) objects and compositions of objects uniformly. It is particularly useful for hierarchical structures like trees. ex. Foo and Collection\<Foo\> have common APIs

**Key Concepts:**

- Composes objects into tree structures to represent part-whole hierarchies.
- Allows clients to treat individual objects and compositions of objects uniformly.
- Uses a common interface for both simple and complex objects.

**Components:**

1. **Component** : An abstract class or interface defining common operations.
2. **Leaf** : A single object that implements the component interface.
3. **Composite** : A complex object that contains child components and implements operations recursively.

**Example:**
Imagine a File System:

- **Component**: `FileSystemElement` (defines common operations)
- **Leaf**: `File` (individual files)
- **Composite**: `Folder` (can contain files or other folders)

**Benefits:**

- Simplifies client code by treating individual and composite objects the same.
- Facilitates recursive structures.
- Enhances scalability by allowing dynamic composition.

**Example 1: Mathematical Expression**  

- **Component**: `Expression` (Abstract class/interface defining an operation like `evaluate()`).  
- **Leaf**: `Number` (Represents a simple numeric value, e.g., `5`, `10`).  
- **Composite**: `Operation` (Represents expressions like `Addition`, `Multiplication`, which combine multiple expressions).  

**Example Structure:**

```md
    (+)
   /   \
  5     (*)
       /   \
      2     3
```

Here, `+` is a composite, `5`, `2`, and `3` are leaves, and `*` is another composite.

---

**Example 2: Grouping of Shapes:**

- **Component**: `Shape` (Defines common operations like `draw()`).  
- **Leaf**: `Circle`, `Square`, `Triangle` (Individual shapes).  
- **Composite**: `Group` (Contains multiple `Shape` elements, allowing nested groups).  

**Example Structure:**  

```md
   Group
  /     \
Circle  Group
        /    \
     Square  Triangle
```

The top-level `Group` contains a `Circle` and another `Group`, which contains `Square` and `Triangle`.

Note:

C++ uses _duck typing_, expecting enumerable types to provide `begin()`/`end()`
A single object can masquerade as a collection

```cpp
Foo* begin() { return this; }
Foo* end() { return this+1; }
```

### Decorator

Facilitates the addition of behaviors to individual objects
Adding behavior without altering the class itself

#### Definition  

The **Decorator Pattern** is a structural design pattern that allows behavior to be dynamically added to individual objects without modifying their code. It promotes flexibility and code reusability by enabling functionalities to be added or removed at runtime.  

#### Key Characteristics  

- Uses **composition** instead of **inheritance** to extend behavior.  
- Wraps an object with additional functionality in a **decorator class**.  
- Can have multiple layers of decorators for complex behaviors.  
- Keeps the **core class** unchanged while adding enhancements dynamically.  

#### Structure  

1. **Component Interface** – Defines the common interface for both concrete components and decorators.  
2. **Concrete Component** – The base object whose functionality can be extended.  
3. **Decorator Abstract Class** – Holds a reference to a component and implements the same interface.  
4. **Concrete Decorators** – Extend functionality by wrapping the component with additional behavior.  

#### Use Cases  

- Extending UI components dynamically.  
- Adding logging, authentication, or compression in a flexible way.  
- Wrapping objects with new behavior without altering their codebase.  

#### Pros & Cons  

##### ✅ Advantages  

- Promotes **Open/Closed Principle** (open for extension, closed for modification).  
- More flexible than inheritance.  
- Allows dynamic addition and removal of behavior.  

##### ❌ Disadvantages  

- Can result in **too many small classes**.  
- May lead to **complex debugging** due to multiple wrappers.  

The **Decorator Pattern** is a powerful tool for designing extensible and maintainable systems while avoiding deep inheritance trees.

#### Differences Between Dynamic, Static, and Functional Decorators

| Feature            | Dynamic Decorator                     | Static Decorator                     | Functional Decorator               |
|--------------------|--------------------------------------|--------------------------------------|------------------------------------|
| **Definition**    | Modifies behavior at runtime        | Applied at compile-time using templates or manually | Uses functions to wrap behavior  |
| **Flexibility**   | Highly flexible, can be added/removed dynamically | Less flexible, needs predefined structure | Moderately flexible, function-based |
| **Implementation** | Uses objects and composition        | Uses subclassing, templates, or explicit wrapping | Uses higher-order functions (lambdas, function objects) |
| **Example Usage**  | Logging, UI components, middleware | Custom framework-specific enhancements (UI frameworks) | Logging, timing, memoization (`@staticmethod` in Python) |
| **Performance**   | May have runtime overhead           | More optimized, as behavior is fixed at compile-time | Typically lightweight |
| **Complexity**    | Can lead to deep wrapper chains     | More structured, but less dynamic   | Easier to understand and apply |

### Façade

The **Facade Design Pattern** is a structural design pattern that provides a simplified interface to a complex subsystem. It acts as a wrapper that hides the complexity of the system, offering a higher-level interface to clients, thus making the system easier to use and interact with.

#### Key Concepts

1. **Simplified Interface**: The facade simplifies access to complex systems by offering a straightforward interface, reducing the need for clients to interact with multiple subsystems.
  
2. **Encapsulation**: The facade hides the internal complexity of the subsystems and delegates tasks to the appropriate subsystem classes, maintaining a clean separation of concerns.

3. **Subsystems**: In systems with many interacting components or classes, the facade pattern reduces the number of components the client must deal with directly, making it easier to use.

4. **Loose Coupling**: By interacting only with the facade, clients are decoupled from the subsystems. This reduces dependencies and makes the system more maintainable.

#### When to Use the Facade Pattern

- **Complex systems**: When the system consists of multiple subsystems with a complex interrelationship, the facade can provide a simple interface for the client.
- **Simplify client interactions**: When you want to reduce the complexity for the client by abstracting the inner workings of the system.
- **Code integration**: When integrating multiple systems or third-party libraries and you want to present a consistent interface.

#### Benefits of the Facade Pattern

- **Ease of Use**: Clients interact with a simple, unified interface, rather than dealing with multiple subsystems.
- **Reduced Complexity**: By using the facade, the client code is simplified, as it does not need to be aware of the internal complexities.
- **Improved Maintainability**: The client is decoupled from subsystem changes, making it easier to maintain and modify subsystems without impacting the client.

In summary, the **Facade Design Pattern** simplifies interactions with complex systems by providing a clean, high-level interface that hides internal complexity. It promotes ease of use, better maintainability, and improved flexibility in system design.

#### Example

```md
          +------------------+
          |   BankFacade     |
          +------------------+
                |  |  |
      __________|__|__|__________
     |           |       |        |
+------------+ +------------+ +------------+
|  Account   | | Transaction| |    Loan    |
+------------+ +------------+ +------------+
| openAccount| | deposit    | | applyForLoan|
| closeAccount| | withdraw   | | approveLoan|
+------------+ +------------+ +------------+
```

### Flyweight

The Flyweight design pattern is a structural pattern used to reduce memory usage by sharing common data among multiple objects. It is particularly useful when there are many objects that share similar state, but only a few distinct variations. Instead of creating new objects for each variation, the Flyweight pattern stores shared data in a centralized object, called a "flyweight," and allows other objects to reference that shared data.

This pattern divides an object’s state into:

1. **Intrinsic state**: Shared data that can be reused by multiple objects.
2. **Extrinsic state**: Data that is specific to an object and varies with each instance.

The Flyweight pattern minimizes memory consumption by sharing the intrinsic state across objects and storing only the extrinsic state as needed.

In essence, it’s about reusing objects wherever possible to save on resources, particularly memory.

---
proxy (property proxy, virtual proxy, communication proxy; proxy vs decorator), chain of responsibility (pointer chain, broker chain), Command, Interpreter (Lexing, Parsing), Iterator (Binary Tree Iterator, Tree Iterator with coroutines), Mediator, Memento, Observer, State, Strategy (Dynamic Strategy, Static Strategy), Template, Visitor (Intrusive, Reflective, Classic Visitor (double dispatch?), Acyclic visitor, multimethods)
