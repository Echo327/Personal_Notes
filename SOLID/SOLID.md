# SOLID

All intertwined and interdependent.
Most effective when combined together.
SOLID principles complement each other, and work together to achieve the common purpose of well-designed software.

- [Solid Responsibility Principle (SRP)](#single-responsibility-principle-srp)
- [Open-Closed Principle (OCP)](#open-closed-principle-ocp)
- [Liskov Substitution Principle (LSP)](#liskov-substitution-principle-lsp)
- [Interface Segregation Principle (ISP)](#interface-segregation-principle-isp)
- [Dependency Inversion Principle (DIP)](#dependency-inversion-principle-dip)
  - [Dependency Injection](#dependency-injection)
- [Inversion of Control - IOC](#inversion-of-control---ioc)

## Single Responsibility Principle (SRP)

---
Every software component should have one and only one responsibility.

**Cohesion** is the degree to which the various parts of a software component are related.
Higher cohesion helps respect the Single Responsibility Principle.

For example,
> A component responsible for both handling measurements on a geometric object and a component for drawing it on screen and doing visual manipulations to it being another component represents higher cohesion whereas one component in charge of both gives a low overall cohesion in the component.

Another example is,
> When you have a journal object that handles both journal entries and saving the journal entries in a file (persistence); this results in low cohesion. Higher cohesion means having a journal function that handles the entries in a journal and another function that handles persistence. This higher cohesion makes it possible to use the persistence function with multiple other functions than with journal.

**Coupling** is defined as the level of inter dependency between various software components.

Loose coupling helps respect the Single Responsibility Principle. Tight coupling is to be avoided.

> For example, a component handling student data and accessing low level database at the same time has high coupling, whereas a student data handling component making use of another component to access low level database is loose coupling.

Every software component should have one and only one reason to change. Concerns should be separated: different classes  handle different and independent tasks.

- Results in low software maintenance cost.

## Open-Closed Principle (OCP)

---
Software components should be closed for modification, but open for extension.

**Closed**: New features getting added to the software component should not have to modify existing code.
**Open**: A software component should be extendable to add a new feature or behavior to it.

Example:
> Interface between a class and other classes it uses making the first class more generic.

Results in:

- Ease of adding new features
- Minimises development and testing cost
- Often requires decoupling (follows SRP)

Caution: Do not follow blindly as it will end up in a huge number of classes making the design too complex.

Example:
> Instead of having a method that sorts by size and another by weight, use a general method or template that takes in what needs to be sorted and the sorting criteria. This way when a new sorting criteria needs to be added, the class is extendable without producing too much unneccessary code.

Example:
> If bug correction requires existing code modification, do it! Bug correction is not a new feature, it's fixing an existing one.

## Liskov Substitution Principle (LSP)

---
Objects should be replaceable with their subtypes without affecting the correctness of the program.

Example:
> Instead of having RacingCar inherit from Car, as one needs Cabin Width and the other Cockpit Width, it breaks LSP. So they should not inherit from one another but instead should both inherit from a generic Vehicle class. (Break the hierarchy)

Example:
> Instead of typecasting for a specific subclass type in the main class, override existing method by making it call another method inside the subclass in order to keep the main class clean by only having itself to call one method. ("Tell, don't ask")

Results in clearer and more generic objects in code.

## Interface Segregation Principle (ISP)

---
No client should be forced to depend on methods it does not use.

**Problem**:
> An All-In-One Xerox printer can do print, scan, or fax tasks. A Xerox *public class* that implements an All-In-One *interface* will have all *methods* (for print, scan, and fax) implemented; whereas an HP *public class* that can only print (but not scan and fax) and that implements the same All-In-One *interface* will only have print implemented, with scan and fax unimplemented. This goes against ISP as HP is forced to depend on methods it does not use. What happens when a call is made to the unimplemented fax *method* in HP? The behaviour is undetermined and can break execution.

**Solution**:
> Split All-In-One *interface* into Print, Scan, and Fax interfaces, each containing printing *methods*, scanning *methods*, and fax *methods* respectively. This way *classes* will implement only interfaces they need. Segregating the *interfaces* like so makes sure unimplemented methods are not called as they don't exist.
*If certains functions are common between a printer and scanner, a parent interface with the common methods can be created.*

### Some Methods of Identification of ISP violations

1. Interface with high number of methods
2. Low cohesion interfaces
3. Empty/blank implementation of methods in classes

### Relationship with other SOLID principles

- 1 interface has a single responsibility (with respect to our previous example, 1 interface is only for printing, and another only for scanning whereas when ISP was not respected there was one interface that could print, scan, and fax)
- Liskov Principle is also respected by segregating (The interface that only prints can be replaced by the class that is a printer that only prints and previously implemented the print-only interface)

### YAGNI - You Ain't Going To Need It

\<text missing\>

## Dependency Inversion Principle (DIP)

---
High-level modules should not depend on low-level modules. Both should depend on abstractions.
Abstractions should not depend on details. Details should depend on abstractions.
<pre>
                High-level module &#8594; Low-level module
                                 &#8595;&#8595;&#8595;
        High-level module &#8594; (abstraction) &#8592; Low-level module
</pre>

**High-level modules** are closer to the functions seen/used by the user.
**Low-level modules** contains implementation details.
Modules can be high- and low-level at the same time as they are relative to the modules with which they interact i.e. a module can be a low-level module compared to another module closer to the user, but higher level compared to a lower level module it interacts with.

> **Example**: Imagine having a class implement an interface (abstraction); the object should not be instanciated directly instead go through a Factory (abstraction; *see Design Patterns*) which instanciates and returns an object.

### Dependency Injection

All dependencies are ***injected*** into the module, the module does not have to worry about dependency resolution. The module only has to care about its main functions.

> **Example**: Adding a Constructor between the high-level module and the Factory module. The high-level module no longer has to initiate any instanciation and can use the object however and whenever it wants.

---
---

## Inversion of Control - IOC

Not a SOLID principle but closely related to DIP.

In our previous example, injection is done in the main control flow/main thread of the program. Frameworks can be used for this to no longer be the case and injection done by a separate thread or even a separate Context. This separate thread or context is called an IOC container. Example Framework in JAVA is Spring.
