# Design Patterns

!! The code in these folders were initially done during an online course and contain a lot of unnecessary comments or notes that should not be present in a final code.

## Table of Contents

1. [Introduction](#introduction)
2. [Types](#types)
3. [Patterns](#patterns)
  i. [Builder](#builder)
  ii. [Factory](#factory)
  iii. [Prototype](#prototype)
  iv. [Singleton](#singleton)
  v. [Adapter](#adapter)

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

Getting the interface you want from the interface you have
