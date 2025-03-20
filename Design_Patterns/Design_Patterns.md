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
  viii. [Decorator](#decorator)
  ix. [Facade](#façade)
  x. [Flyweight](#flyweight)
  xi. [Proxy](#proxy)
  xii. [Chain of Responsibility](#chain-of-responsibility)
  xiii. [Command](#command)
  xiv. [Interpreter](#interpreter)
  xv. [Iterator](#iterator)
  xvi. [Mediator](#mediator)
  xvii. [Memento](#memento)
  xviii. [Observer](#observer)
  xix.[State](#state)
  xx. [Strategy](#strategy)
  xxi. [Template](#template)
  xxii. [Visitor](#visitor)

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

### Proxy

The **Proxy Design Pattern** is a structural design pattern that provides an object representing another object. It acts as a surrogate or placeholder, controlling access to the real object. The proxy pattern is used to add an extra layer of control over the real object, often to perform actions like lazy initialization, access control, logging, or monitoring.

There are different types of proxies:

1. **Virtual Proxy**: Delays the creation and initialization of expensive objects until they are needed, which helps with performance optimization.
  
2. **Remote Proxy**: Represents an object that is in a different address space, often used in distributed systems where objects are accessed remotely.
  
3. **Protective Proxy**: Controls access to an object by ensuring that only authorized clients can interact with it, often for security purposes.
  
4. **Cache Proxy**: Provides cached access to an object, allowing for faster retrieval of frequently accessed data by avoiding unnecessary computation or data retrieval.

By using a proxy, you can decouple the client from the real object, enabling greater flexibility and control over how the real object is used.

Additionally there exists other types on non-core proxies:

1. **Property Proxy**: This term typically refers to a proxy that controls access to specific properties or attributes of an object. It might be used for things like lazy loading or providing access control to a specific aspect of the object. While it's not one of the primary four types, it could be seen as a specialized form of the Virtual Proxy or Protective Proxy.

2. **Communication Proxy**: This generally refers to a proxy that handles the communication between objects, often in distributed systems or client-server setups. It would be most closely related to the Remote Proxy, which acts as an intermediary for objects that are located in different address spaces or on different machines.

#### Comparison of core proxy design patterns

| **Proxy Type**       | **Purpose**                                                                 | **Common Use Cases**                                                    | **Key Characteristics**                                            |
|----------------------|-----------------------------------------------------------------------------|-------------------------------------------------------------------------|--------------------------------------------------------------------|
| **Virtual Proxy**     | Delays the creation/initialization of an expensive object until it’s needed. | Performance optimization, lazy loading of resources.                   | Initializes the real object only when it's required.               |
| **Remote Proxy**      | Represents an object in a different address space, often on a remote machine. | Distributed systems, remote method invocation (RMI).                   | Handles communication with objects that reside remotely.          |
| **Protective Proxy**  | Controls access to the real object, often for security or permission reasons. | Access control, security enforcement.                                  | Provides authorization checks before delegating actions to the real object. |
| **Cache Proxy**       | Caches the result of expensive operations to improve performance on subsequent accesses. | Caching frequently requested data or operations.                       | Stores and reuses results from previous operations to optimize speed. |

### Chain of Responsibility

A chain of components who all get a chance to process a command or query, optionally having default processing implementation and anbility to terminate the rpocessing chain.

The **Chain of Responsibility** design pattern is a behavioral design pattern that allows a request to be passed along a chain of potential handlers until it is handled by an appropriate handler. Each handler in the chain has the ability to either handle the request or pass it along to the next handler in the chain.

**Chain of Responsibility** pattern defines a request-handling mechanism in which a chain of objects is given the chance to handle a request. Each object in the chain either processes the request or passes it to the next handler in the chain. This pattern decouples the sender of a request from its receivers, allowing multiple objects to process the request in a flexible and extensible manner.

#### Key Characteristics (Chain of Responsibility)

- **Handlers**: The objects that process or forward the request.
- **Chain**: The sequence of handlers where each handler either processes the request or forwards it to the next handler.
- **Decoupling**: The sender of the request is decoupled from the handler(s), promoting loose coupling.
  
#### Benefits

- **Reduced coupling**: The sender does not need to know which handler will process the request.
- **Flexible processing**: New handlers can be added to the chain without changing the request sender or existing handlers.
- **Responsibility assignment**: The responsibility for handling a request can be distributed among multiple objects.

The Chain of Responsibility pattern is particularly useful in situations where multiple handlers may be able to process a request, and the specific handler is not known in advance.

#### Types of implementation

| **Type**                | **Description**                                                                                         | **Use Case**                                                                                   |
|-------------------------|---------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------|
| **Single Chain**         | A linear chain where each handler either processes the request or passes it to the next handler.         | Classic use case where the request follows a specific order until it is processed.            |
| **Multiple Chains**      | Multiple chains for different types of requests, where the request is routed to the appropriate chain.   | When requests need to be handled by different categories of handlers working in parallel.      |
| **Circular Chain**       | Handlers form a circular loop, and requests cycle through the chain.                                    | When requests need to be processed in a round-robin or repeating manner.                       |
| **Conditional Chain**    | The next handler is determined by specific conditions or the state of the request.                      | When decisions on which handler should process the request depend on dynamic conditions.       |
| **Fallback Chain**       | Handlers are arranged to provide a failover mechanism, passing the request to the next handler if one fails. | For error handling or situations where request processing needs to continue in case of failure.|
| **Composite Chain**      | Handlers may themselves be chains, allowing for more complex handling by delegating requests to sub-chains. | When responsibility is distributed among smaller sub-chains working together in the same process.|

The **Pointer Chain** and **Broker Chain** are specialized variations that can be considered as extensions or specific implementations of the more general **Chain of Responsibility** pattern. These two types don't necessarily represent entirely new concepts but rather refine or combine aspects of the previous 6 types (Single, Circular, etc.). Here’s how they relate:

##### placeholder

##### **1. Pointer Chain**

A **Pointer Chain** typically involves handlers that maintain a reference (pointer) to the next handler in the chain. This can fit into a few of the earlier mentioned Chain of Responsibility types:

| **Type**                | **Pointer Chain Relation**                                                                                 |
|-------------------------|------------------------------------------------------------------------------------------------------------|
| **Single Chain**         | In a **Single Chain**, handlers hold a pointer (reference) to the next handler, making it a natural fit. Each handler is linked via pointers. |
| **Multiple Chains**      | In **Multiple Chains**, each chain could have handlers holding pointers to the next handler in their respective chain. The pointers in this case allow for dynamic routing of requests to different chains. |
| **Circular Chain**       | A **Circular Chain** inherently involves handlers pointing to each other in a loop, so a **Pointer Chain** could be used here as well. Each handler has a pointer to the next, and once the last handler is reached, it points back to the first handler, forming a loop. |
| **Conditional Chain**    | **Pointer Chains** allow dynamic decision-making to determine which handler is next, and this can fit into **Conditional Chains** where the flow is decided by conditions. Handlers may point to different subsequent handlers based on conditions. |
| **Fallback Chain**       | In a **Fallback Chain**, pointers could dynamically switch to the next available handler in case one handler fails, allowing the next handler to take over (failover). |
| **Composite Chain**      | In a **Composite Chain**, handlers that themselves are chains (i.e., composed of sub-chains) can hold pointers to their respective sub-handlers, enabling dynamic delegation within a more complex setup. |

In essence, a **Pointer Chain** is a flexible implementation where each handler has a reference to the next, making it applicable to the **Single**, **Multiple**, **Circular**, **Conditional**, **Fallback**, and **Composite** types. The key feature is the dynamic nature of how the handlers are linked and how requests can flow.

#### **2. Broker Chain**

The **Broker Chain** refers to a central entity (the "broker") that coordinates the passing of requests to handlers, and it typically involves more complex decision-making logic. It can be linked with various types in the following ways:

| **Type**                | **Broker Chain Relation**                                                                                   |
|-------------------------|------------------------------------------------------------------------------------------------------------|
| **Single Chain**         | In a **Single Chain**, the broker could be responsible for dynamically managing which handler should be invoked next. This would be a centralized decision point before moving through the linear sequence of handlers. |
| **Multiple Chains**      | A **Broker Chain** fits naturally with **Multiple Chains** when a central broker decides which chain should handle a request based on the request's characteristics, routing it to the correct chain. |
| **Circular Chain**       | In a **Circular Chain**, the broker can be the entity that monitors the flow and determines if and when the request should cycle back through the chain. It can control the looping process or reset the flow of the request. |
| **Conditional Chain**    | A **Broker Chain** can work with **Conditional Chains** by making decisions about which handler in the chain should process the request based on predefined conditions. The broker manages these decisions dynamically. |
| **Fallback Chain**       | In a **Fallback Chain**, a broker can serve as the decision point when a handler fails or is unavailable, routing the request to the next handler in the fallback mechanism. |
| **Composite Chain**      | A **Broker Chain** is useful in a **Composite Chain** for orchestrating requests across multiple sub-chains, deciding how to delegate tasks to composite elements or deciding the flow of requests across various components of the system. |

The **Broker Chain** primarily introduces a **centralized control mechanism** for determining how requests should flow through the chain. It allows for **complex decision-making** and ensures that requests are routed correctly, either through multiple chains or different handlers, depending on the circumstances.

#### Summary Table Comparing Pointer and Broker Chain

| **Chain Type**           | **Pointer Chain**                                                                 | **Broker Chain**                                                                |
|--------------------------|-----------------------------------------------------------------------------------|---------------------------------------------------------------------------------|
| **Single Chain**          | Handlers hold pointers to the next handler in a linear sequence.                  | A broker manages the routing of requests to handlers in the linear chain.       |
| **Multiple Chains**       | Each chain's handlers hold pointers to the next handler in their respective chains. | The broker decides which chain to route the request to based on its characteristics. |
| **Circular Chain**        | Handlers point to each other in a loop, forming a circular structure.            | The broker controls how the request cycles through handlers in a circular manner. |
| **Conditional Chain**     | The flow between handlers can be dynamic, depending on conditions.                | The broker decides which handler to route the request to based on conditions.   |
| **Fallback Chain**        | Handlers dynamically point to the next available handler if the current one fails. | The broker manages failover by routing requests to the next available handler. |
| **Composite Chain**       | Handlers can delegate requests to sub-chains, forming a more complex structure.   | The broker orchestrates requests across sub-chains or different components.     |

Both **Pointer Chains** and **Broker Chains** introduce flexibility, dynamic decision-making, and centralized control over the flow of requests, fitting naturally into the previously discussed types of Chain of Responsibility implementations.

### Command

The Command design pattern is a behavioral design pattern that turns a request or action into a stand-alone object. This allows the parameterization of clients with queues, requests, and operations. Essentially, it decouples the sender of a request from the object that executes the request.

#### Key Concepts (Command)

- **Command**: Represents an action or request. It encapsulates all details of the request, including the method call, parameters, and the receiver.
- **Invoker**: The object that initiates the request or command but does not need to know how the request is handled. It simply calls the execute method on the command.
- **Receiver**: The object that performs the actual work or action when the command is executed.
- **Client**: The object that creates and sets up the command object.

#### Benefits (Command)

1. **Decoupling**: The sender of the request does not need to know how the request is processed or who will execute it. It just triggers the command, and the command takes care of the rest.
2. **Extensibility**: New commands can be added without changing existing code, as you can introduce new command objects without altering the invoker or receiver.
3. **Undo/Redo functionality**: Command objects can be stored in a stack or a queue, allowing you to easily implement undo/redo functionality.
4. **Composite Commands**: Multiple commands can be combined into a single command, allowing for complex actions to be executed in a simple, unified way.

#### Use Cases (Command)

- **Transaction management**: Where multiple actions need to be bundled together and executed in a specific order or undone if necessary.
- **Menu systems in GUI applications**: Where commands are tied to UI elements like buttons, allowing a flexible way of invoking different actions.
- **Macro recording**: In some applications, user actions can be recorded and replayed as a sequence of commands.

In short, the Command pattern turns a simple request into an object that can be passed around, queued, logged, or even undone, offering flexibility and separation of concerns in handling requests and operations.

### Interpreter

The Interpreter Design Pattern is a behavioral design pattern that provides a way to define a grammar for a language and a mechanism for interpreting sentences in that language. It involves defining an abstract representation for each element of the grammar, typically as classes, where each class implements an interpret method that evaluates or interprets the specific component of the language. This pattern allows for building a complex language structure by combining simpler expressions and enables easy extension by adding new grammar rules. The key components of the pattern typically include the abstract expression, terminal expressions, non-terminal expressions, and a context that holds information needed for interpretation.

```ascii
              +----------------+
              |   Context      |
              +----------------+
                      ^
                      |
              +---------------+
              |   Expression  |
              +---------------+
              | +interpret()  |
              +---------------+
                 /        \
    +----------------+    +--------------------+
    | TerminalExpr   |    | NonTerminalExpr    |
    +----------------+    +--------------------+
    | +interpret()   |    | +interpret()       |
    +----------------+    +--------------------+
                                   |
                         +------------------+
                         |  AddExpression   |
                         +------------------+
                         | +interpret()     |
                         +------------------+
```

### Iterator

The **Iterator Design Pattern** is a behavioral design pattern that provides a way to sequentially access elements of a collection (like a list, array, or any other aggregate object) without exposing the underlying structure of the collection. It allows a client to traverse through the collection without needing to know its details.

#### Iterator Key Concepts

1. **Iterator**: This is an object that is responsible for traversing through the elements of the collection. It provides methods for accessing the next element and checking if there are more elements to iterate over.

2. **Aggregate**: This is the collection that holds the elements (like a list, stack, or queue). The collection is responsible for providing an iterator that can be used to traverse its elements.

3. **ConcreteIterator**: A specific implementation of the Iterator interface, this is the object that holds the state of the iteration (such as the current position in the collection).

4. **ConcreteAggregate**: This is a specific collection class that implements the Aggregate interface. It creates and returns an iterator for traversing its elements.

#### Iterator Structure

- **Iterator Interface**: It defines the methods for accessing elements (`next()`, `hasNext()`, etc.).
- **ConcreteIterator Class**: Implements the iterator methods for a specific collection.
- **Aggregate Interface**: This defines the method for creating an iterator (`createIterator()`).
- **ConcreteAggregate Class**: Implements the `createIterator()` method to return an instance of a concrete iterator.

#### Advantages

- **Separation of Concerns**: The iterator handles the traversal logic, while the collection can focus on storing data. This makes the code easier to maintain.
- **Encapsulation**: The client doesn’t need to know the details of the underlying collection (like its data structure) to traverse through it.
- **Flexibility**: Multiple iterators can be created for the same collection, allowing different ways to traverse the same data (e.g., forward, reverse, etc.).

#### Iterator Use Cases

- **When you want to access elements of a collection sequentially without exposing the internal structure.**
- **When you want to support multiple traversal mechanisms.**
- **When you want to provide a uniform interface for different types of collections.**

This pattern is often used in situations where you want to separate the logic for accessing the elements of a collection from the collection itself.

#### Common Iterator Examples

1. **Collection Iterator**
   **Description:**  
   This is the most common use of the Iterator pattern, where an iterator is provided to traverse a collection (like a list, array, or set) without exposing the internal structure. The iterator allows sequential access to each element, one at a time.
   **Use Case:**  
   When you have a collection of objects and need a way to iterate through them without exposing the underlying details of the collection (e.g., whether it's an array, linked list, or hash set). This is useful in situations where the collection may change or when different collections may need to be iterated in the same way (e.g., `ArrayList` vs. `LinkedList`).
2. **Reverse Iterator**
   **Description:**
   A reverse iterator traverses a collection from the last element to the first. This is an extension of the basic iterator, providing the ability to access elements in reverse order.
   **Use Case:**  
   When you need to process a collection in reverse order, such as undoing operations in a history stack, or when displaying elements in a UI from the end to the beginning (like a playlist of songs displayed in reverse order).
3. **Bidirectional Iterator**
   **Description:**  
   This iterator allows traversal in both directions, forward and backward. It's often used in doubly linked lists, where each node points to both its next and previous elements.
   **Use Case:**  
   This is useful in scenarios like navigating through a web browser history where the user may go back and forward between pages, or in a navigation system where elements can be traversed both ways (e.g., a playlist where users can move back and forth).
4. **Tree Iterator**
   **Description:**  
   This iterator is specifically designed for traversing hierarchical structures like trees. It allows traversal in various orders (in-order, pre-order, post-order).
   **Use Case:**  
   When dealing with tree-like data structures (e.g., file systems, organizational hierarchies, or expression trees), you need an iterator to traverse and access nodes. It simplifies processing elements of the tree in a structured manner.
5. **Composite Iterator**
   **Description:**  
   A composite iterator is used when you have a collection that contains other collections (like a collection of collections). It ensures that elements within the nested structures can be iterated over seamlessly as if they were all part of a single, flat collection.
   **Use Case:**  
   This is ideal in situations like processing a directory structure, where a directory may contain both files and subdirectories. You can iterate over everything without worrying about which type of object you're dealing with (file or subdirectory).
6. **Filter Iterator**
   **Description:**  
   A filter iterator provides a mechanism to iterate over a collection while applying a filter criterion to select only the elements that meet a specific condition.
   **Use Case:**  
   When you have a large collection and you want to process only a subset based on certain conditions, such as finding all even numbers in a list or all active users in a user list. This iterator allows filtering elements without modifying the original collection.
7. **Lazy Iterator**
   **Description:**  
   A lazy iterator computes elements only when they are needed, typically used in situations where elements are expensive to compute or when the collection is infinite.
   **Use Case:**  
   This is useful in scenarios where the entire collection is not available upfront (e.g., streaming data, large data sets, or generating sequences on the fly like Fibonacci numbers). A lazy iterator ensures that elements are only produced as needed, preventing memory overload.
8. **Circular Iterator**
   **Description:**  
   A circular iterator returns to the start of the collection once it reaches the end. It loops indefinitely through the elements.
   **Use Case:**  
   When you need to repeat processing of the elements continuously, like in a round-robin scheduling algorithm, cyclic animation, or a rotating playlist where the music repeats once the end is reached.
9. **Peekable Iterator**
   **Description:**  
   A peekable iterator allows not only iteration over elements but also the ability to "peek" at the next element without advancing the iterator. This is useful when you need to know what's coming up without consuming the element.
   **Use Case:**  
   Useful in scenarios like parsing or processing streams of data where the next item in the sequence is needed to make a decision but doesn't want to be consumed yet (e.g., tokenizing a stream of text or reading data files with certain rules).
10. **Multiple Iterators**
   **Description:**  
   Multiple iterators allow you to have separate iterators for the same collection, enabling you to iterate over the collection in different ways simultaneously.
   **Use Case:**  
   This is used when multiple types of traversal are needed on the same collection, such as when you might want to access the elements both by index and by value (e.g., having both a sorted iterator and a regular iterator over a collection of objects).
11. **Tree Iterator with Coroutines**
  **Description:**
  A Tree Iterator with Coroutines combines tree traversal with the use of coroutines for lazy evaluation. It allows traversal of tree structures like a standard tree iterator but can pause and resume the iteration process, yielding nodes lazily. Coroutines are used to enable more efficient memory usage and processing.
  **Use Case:**
  When working with large hierarchical structures (like trees or graphs) where you want to pause the iteration and process other tasks, resuming from the last position. It's especially useful for deep tree structures where loading each part of the tree or node dynamically makes sense, like a database traversal or parsing large XML/JSON documents in chunks.

### Mediator

The **Mediator** design pattern is a behavioral design pattern that promotes loose coupling in a system by centralizing communication between objects. Instead of having objects communicate directly with one another, they communicate through a mediator object. This way, the mediator handles all interactions, which helps to reduce the complexity and dependencies between the objects.

#### Key Points of the Mediator Pattern

1. **Centralized Communication**: The mediator acts as a central point of contact for all communication between components. Rather than objects directly interacting with one another, they send their messages to the mediator.
2. **Decoupling**: By relying on a mediator to manage communication, objects are decoupled from each other. This makes it easier to modify, extend, or maintain the system, as changes to one object won’t affect others directly.
3. **Simplifies Complex Interactions**: In systems with many objects interacting with each other, the mediator pattern reduces the number of connections that need to be managed. Without it, the interactions between objects might form a complex web of dependencies. The mediator helps simplify this by reducing the direct dependencies.
4. **Coordination of Components**: The mediator can coordinate the actions of various components, ensuring that the right sequence of actions occurs or that only the necessary components are involved in a particular interaction.

#### Use Cases for the Mediator Pattern

- **GUI Systems**: In graphical user interfaces (GUIs), there may be multiple elements (buttons, text fields, checkboxes, etc.) that need to communicate with each other. Instead of each element interacting directly, a mediator (such as a controller) can manage the interactions.  
- **Chat Applications**: In a chat system, users might send messages to each other, but rather than each user directly messaging others, a chat room or server can act as a mediator to manage the message flow.
- **Workflow Management**: In systems where different steps or components need to be orchestrated in a specific order, a mediator can handle the coordination of those steps.

#### Benefits (Mediator)

- **Reduced Complexity**: Since objects don’t need to know about each other, the system becomes easier to understand and modify.  
- **Better Maintainability**: Changes to one object are less likely to affect others since they don’t have direct interactions.
- **Improved Flexibility**: New components can be added to the system with minimal impact on existing components because the mediator handles all communication.

#### Drawbacks (Mediator)

- **Mediator Complexity**: If the mediator itself becomes too complex or handles too many responsibilities, it can become a bottleneck in the system.
- **Overhead**: The mediator adds another layer of abstraction and can introduce overhead if it’s not used appropriately.

In summary, the Mediator pattern helps manage communication between a group of objects by centralizing it in a mediator, simplifying the interactions and improving the maintainability and flexibility of the system.

### Memento

The **Memento design pattern** is a behavioral design pattern that allows an object to capture and externalize its internal state without violating encapsulation. This captured state can later be restored, allowing the object to return to that saved state at a later time. 

#### Key Concepts (Memento)

1. **Originator**: The object whose state is being saved or restored. It can create and restore a memento object that holds its internal state.
2. **Memento**: A snapshot of the Originator's internal state. It doesn't expose any details about the state, ensuring encapsulation. The Memento only stores the state and doesn't alter it.
3. **Caretaker**: This component is responsible for managing the mementos. It keeps track of multiple mementos (often in a list or stack) but doesn't alter their content or manage their state directly. It can request the Originator to save or restore its state using a memento.

#### How It Works

- **Saving State**: When the state of an object (Originator) needs to be saved, it creates a memento object that holds the current state. This memento is then passed to the Caretaker for storage.  
- **Restoring State**: At a later time, the Caretaker can request the Originator to restore its state from the memento, effectively reverting the object to its prior condition.

#### Advantages (Memento)

- **Preserves encapsulation**: The internal details of the object’s state are hidden in the memento, ensuring that the object's internal implementation remains protected.  
- **Undo/Redo functionality**: The Memento pattern is useful in scenarios where undo/redo functionality is needed, such as in text editors or games.

#### Use Cases (Memento)

- Implementing undo/redo mechanisms in software applications.
- Saving checkpoints in a game or long-running process.
- Storing the history of an object’s state in systems like databases or version control.

In essence, the Memento pattern helps in separating the responsibility of saving and restoring the state from the object itself, while keeping the object’s internal structure hidden and protected.

### Observer

The **Observer Design Pattern** is a behavioral design pattern used to establish a one-to-many relationship between objects. In this pattern, a **subject** (also called the "observable") maintains a list of its dependents, known as **observers**, and notifies them automatically of any changes in its state.

#### Key Concepts (Observer)

1. **Subject**: The object that holds the state and notifies its observers of any changes. It is responsible for maintaining the list of observers and updating them when its state changes.
2. **Observers**: These are the objects that are dependent on the state of the subject. They need to be notified whenever there is a change in the subject’s state. Each observer registers with the subject to receive notifications.
3. **Notification Mechanism**: When the state of the subject changes, it triggers a notification to all registered observers, ensuring they are updated with the new state.

#### Benefits (Observer)

- **Loose Coupling**: The subject and observers are loosely coupled because the subject doesn't need to know the details about the observers; it just sends notifications. Likewise, observers don't need to know how the subject is implemented.  
- **Dynamic Relationship**: Observers can be added or removed from the subject at runtime, which makes the system flexible and adaptable to changes.
- **Decouples Responsibility**: The responsibility for maintaining consistency between different parts of the system is shared between the subject and the observers.

#### Use Cases (Observer)

- **Event Handling Systems**: Where one event triggers multiple reactions.
- **User Interface (UI) Components**: A model-view pattern where the model (subject) notifies the view (observer) when data changes.
- **Real-Time Data Monitoring**: Stock prices, weather systems, or sensors that update their data to subscribers.

The observer pattern is most useful when you want to ensure that multiple objects are updated automatically in response to changes in a central object without tightly coupling the components together.

### State

The state machine design pattern is a behavioral design pattern that allows an object to change its behavior when its internal state changes. This pattern is useful for modeling complex systems where an object can be in one of several states, each with distinct behaviors and transitions.

### Key Concepts (State Machine)

1. **States**: Represents the various conditions or modes in which an object can exist. Each state defines specific behaviors and responses to events.
2. **Transitions**: The rules that determine how an object moves from one state to another. Transitions are often triggered by events or conditions.
3. **Context**: The object that maintains the current state and delegates behavior to the active state. It encapsulates the state machine and manages state transitions.
4. **Events**: Actions or occurrences that can trigger state transitions. Events can originate from user interactions, system inputs, or internal conditions.

### Benefits (State Machine)

- **Separation of Concerns**: Each state encapsulates its behavior, making the code easier to understand and maintain.
- **Scalability**: New states can be added with minimal impact on existing code.
- **Clarity**: The flow of state transitions makes the logic of state-dependent behaviors explicit.

### Use Cases (State Machine)

- User interface elements (e.g., buttons that change states based on user interactions).
- Workflow systems (e.g., order processing that varies depending on the order status).
- Protocols (e.g., network communication states).

In summary, the state machine design pattern provides a structured approach to managing state-dependent behavior, enhancing the clarity and maintainability of complex systems.

### Strategy

### Template

### Visitor

---
Strategy (Dynamic Strategy, Static Strategy), Template, Visitor (Intrusive, Reflective, Classic Visitor (double dispatch?), Acyclic visitor, multimethods)
