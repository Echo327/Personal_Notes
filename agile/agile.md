# Agile Software Development

## Why and How

### Waterfall **Model**
* Royce (1970)
<pre>
    System      -->    Software    -->  Analysis  -->  Program  -->  Coding  -->  Testing  -->  Operations  
 Requirements   <--  Requirements  <--            <--  Design   <--          <--           <--
</pre>

* Updated/Modern
<pre>
 Feasibility  -->  Requirements  -->  Specification  -->  Global  -->  Detailed  --> Implementation --> V & V --> Distribution   
   Study      <--                <--                 <--  Design  <--   Design   <--                <--       <--
</pre>

Drawbacks/Inconveniences:
* Late appearance of code: Code provides a more direct feedback for feasibility and often times problems appear only when coding
* Doesn't take into consideration changes during steps
* Maintenance is not taken into account
* Division of labor hampering Total Quality Management
* Impedance mismatches between analysis, design, and implementation (due to reliance on intermediary documents)
* Highly synchronous model

**Agile** adresses the above problems while also rejecting the problem-prone upfront requirements phase (**requirements change** over time; so the time spent **formalising** requirements should be minimised). This also reduces waste (Lean) because of requirements not being met. **Agile replaces requirements with user stories.**

Some concrete examples of how agile methodologies address these issues:
* Beck (XP): Requirements gathering is an activity that provides details just before it is needed in development.  
* Cohn (SCRUM): All work occurs within the repeated cycle of sprints with the absence of upfront analysis or design phase.  
* Poppendieck (Lean): Requirements should be more aptly called candidate solutions and not set in stone. "separating requirements from implementation is just another form of handover" 

## Manifesto (2001)
> agilemanifesto.org

```
Individuals and Interactions            >               Processes and Tools
Working Software                        >               Comprehensive Documentation
Customer Collaboration                  >               Contract Negotiation
Responding to Change                    >               Following a Plan
```

## The 12 Principles *(not verbatim)* and Values:
*  **New and reduced role for manager**
No assignment of tasks to project members by project manager. The team self-organises itself instead.

> 11. **Do not over-manage developers**; the best architectures, requirements, and designs emerge from self-organizing teams.

> 5. Build projects around motivated individuals giving them the environment they need, **support, and trust**.

*  **No "Big Upfront" steps**
Coding to produce software starts right away. Design and reevaluation of requirements are assessed continuously during the coding process instead of being fixed from the start.

> 1. Highest priority is to **satisfy customer** through early and continuous delivery of valuable software.

> 3. **Deliver working software frequently**; give preference to shorter timescales.

*  **Iterative development**
Project members communicate on a regular basis. For example, every day, or every few days, or every few weeks depending on the scope of the project in a more progressive way. *i.e.* Development cycles should last from one day to a few weeks requiring each cycle to have elicitation, design, development, and testing on a usually limited scope.

> 4. Business people and developers should **work together**.

> 2. Welcome changing requirements, *even late in development*. The **ability to change gives competitive advantage**.

> 6. **Face-to-face conversation** is the most efficient and effective way for *conveying information*.

> 8. Promote sustainable development: **maintaining constant pace**; *and avoid crunch?*

> 12. Communicate to **reflect on successes and failures** in order to **adjust team behaviour accordingly**.

*  **Limited, negotiated scope**
System does exactly what's needed *i.e.* build functionality that is strictly needed; this reduces waste (virtual and physical).

> 10. **Simplicity** *-the art of maximising the amount of work not done-* is essential; write simple code as much as you can, or in other words do not leave your code complicated and personal, make it simple, easy to read, and accessible (in terms of readability) to everyone.

> **Negotiator Scope**
> [Beck 05] Extreme Programming Explained by Kent Beck, Cynthia Andres
> 
>>
>> Write contracts for software development that fix time, costs, and quality but call for **ongoing negotiation** of the precise scope of the system. Reduce risk by signing a **sequence of short contracts** instead of one long one.
>>
>
>> You can move in the direction of negotiated scope. Big, long contracts can be split in half or thirds, with the optional part to be exercised only if both parties agree. Contracts with high costs for change requests can be written with less scope fixed up front and lower costs for changes.
>
> In other words, (blind) commitment to (both) delivery date and a specific set of functionalities do not mix well. Sometimes focusing on delivery date while forgoing some functionalities is needed while other times delivery date needs to be flexible in regards to a certain set of functionalities. 

*  **Focus on quality achieved through testing**
Testing makes for better quality products.

> 7. (Tested) **Working software** is the **primary measure of progress**.

> 9. **Continuous attention** to technical excellence and good design enhances agility.

## Updated Principles

Over the years, this has given rise to multiple agile methodologies and the corresponding update to the agile principles to adress issues or fill in the gaps.

### Agile Methods/Methodologies
Some of the most popular agile methods are:

*  Extreme Programming (**XP**)
Response to UML (Unified Modelling Language) and CMMI (Capability Maturity Model Integration) etc. that emphasize process and documentation; but **what matters is the program and programming**

*  **Lean** Software
Made for engineering fields, especially the car industry. **Get rid of waste** (ex. useless documentation, ...); **concentrate on what is delivered to customer**

*  **Crystal** Methodology
Set of methods with various degrees of importance to process

*  **SCRUM** (most widely adopted)
Management method emphasizing ideas via **self-organising teams** (compared to closely managed one) and short release interations (**Sprints**)

*  (...)

### Organisational Principles
*mostly from SCRUM, some from XP*

1. Put the customer at the center

> Build the right system, not just build one system right.

**Real/Actual** customers should be involved not only at the beginning and end but also in the development phase to make sure that the system that is actually desired/expected is being built. Documents/requirements that "replace" the customer can only lead to waste. This also helps build a relationship between all parties involved in the project.

> XP: Embed the customer in the project with the developers (although this can be difficult to implement and lacks diversity i.e. one customer is not representative of many customers)
> SCRUM: defines a product owner who decides after an iteration of development whether it is acceptable or not (works better as product owner is committed profesionally to provide the right system)

***Customer involvement doesn't replace requirements but complements it.***

2. Accept change
In software engineering, extendibility is defined as the ability to change easily in response to changing user requirements. One of the best techniques to achieve this is object-oriented programming. Agile puts extendibility in a very abstract manner; OO-programming still therefore remains a good way of achieving this. 

3. Let the team self-organise

> The team members doing the actual work manage themselves. The SCRUM master/manager/leader is there to guide the flow and provide support.

In agile, the manager no longer assigns specific tasks to members on a day-to-day basis. Tast assignment is coollectively decided by members of the group. The manager/SCRUM master is there to provide support and help in difficult situations: listen, explain what can be done, coach, mentor, catch errors, remove impediments, adress skepticism that might ruin team spirit, *etc.* to developers.

*Sometimes, a traditional manager is still preferred depending on the project.*

4. Maintain a sustainable pace

> Avoid extreme pressure to meet deadlines.

> The best work is done in peace, quiet, and respect.

People perform best when not overstressed. Overtime should always be accompanied with the appropriate following relaxation/break and "crunch" should be avoided.

This can most of the time be achieved by:
- frequent code merges,
- maintaining executable, test-covered, high quality code,
- constant refactoring in order to keep fresh and aler minds,
- collaborative work,
- constant testing,
- (...)

5. Produce minimal software:
    - Produce minimal functionality
      > YAGNI: You Ain't Gonna Need It
      Only code what a real customer is going to use; do not produce waste. In other words, do not waste time on what you think you are going to need and instead *focus on what is strictly needed*.

      > Only do what user stories ask for. Not more. 

      Extra features can increse complexity of the code and drive up costs non-linearly.

*Different user groups can still provide different user stories. Just because one user doesn't need a functionality, doesn't mean another is not asking for it. What is wasteful is writing code that no user story is asking for.*

***The "lean" view***
> Seven wastes of software development:
>> - Overproduction: Extra/Unused features  
>> - Inventory: Partially unreleased developed work  
>> - Extra Processing: Intermediate/Unused artifacts  
>> - Motion: Seeking (missing) Information about customer or algorithmic needs  
>> - Defects: Escaped defects not caught by tests/reviews  
>> - Waiting/Customer Waiting  
>> - Transportation: Handoffs (*e.g.* in manufacturing, it would be the transport of raw materials and finished products; in software this would be equal to several notations and tools used to work on the same thing like in UML or having to translate and communicate between multiple formalisms in a programming language)  

    - Produce only the product requested
      >  Do not **over**-worry about producing extendable software
      Start by coding the simplest thing that could work. "Ideally", it "should" stand the test of time and change by being reusable, being written in such a way that it looks beyond immediate goals or requirements. *The only way to get there is through experience or by starting from a simple code that gets the job done; the perfect solution is not just going to appear out of thin air; and the perfect solution doesn't need to be found as long as the code meets requirements.*  

    - Develop only code and test
      > Code
      > Test
      
      > Cockburn: "You get no credit for any item that does not result in running, tested code." (unless for final delivrables such as training materials and delivery documentation.)
      Do not put too much emphasis on plans or intermediate documents that will not be beneficial to and/or never be seen by the customer.

### Technical Principles 
*Comes from XP and other agile methods*

6. Develop iteratively
    - Produce frequent working iterations
    
    > * Vertically-layered clusters
    >  User Interface   ^
    >  Business Logic   |
    >  Networking       | Iterations
    >  Database         |
    A lot of time is spent at the start without producing any useful functionality.   

    >                                  UI1     UI2     UI3
    >  Horizontally-layered           Logic1  Logic2  Logic3
    >       clusters                   Net1    Net2    Net2     ...
    > ("the more agile way")           DB1     DB2     DB3
    >                                 ---------------------->
    >                                       Iterations

    Each (frequent) iteration produces a working system. Typically, an agile project uses 2 to 6 weeks as standard for adopted iterative development. It can also go down to few days or even one day, the focus should be on frequent iterations according to what is needed for the project. 

    - Freeze requirements during iterations (Closed-Window Rule)
      Addition of functionality during an iteration not defined in user stories means the cancellation of the current sprint (SCRUM).
      This helps bring order and focus to what is being worked on.
      *A sprint is interrupted and restarted only in extreme rare cases; mostly to adapt to competition.*

Alternatively:
> Dual development (mixed Agile/non-agile): build infrastructure early on and later produce releases while respecting release dates with respect to getting working code to the user.

7. Treat tests as a key resource:
    - Do not start any new development until all tests pass
    Regression test suite: A collection of tests including tests that failed in the history of the project, to make sure that faults that already occured in the past do not occur again when implementing new features

    It is forbidden to start adding new functionality until we are sure that all existing tests pass; all the existing functionality is reasonable well-implemented as guaranteed (or at least supported).

    *in some cases, some tests might be considered currently non essential and might not require passing testing before moving on* 
    
    - Test first

    - (TFD: Test First Development; TDD: Test-Driven Development)

8. Express requirements through scenarios/user stories

    User story: something the user wants. *e.g.* change tax calculations on invoices

    Standard form:
    > "As a <user_or_role>
    > I want <business_functionality>
    > so that <business_justification>
    
    Example:
    > "As a _customer_, I want _to see a list of my recent orders_, so that _I can track my purchases with a company_."

    > "As a _registered user_, I want to _log in_, so I can _access subscriber content_.

    User stories are generated on-the-go before every sprint. They provide a good description of how the system needs to perform in a typical scenario.

    *There are many ways to accomplish something, hence the need for abstraction in user stories. For example, 2*2 = 4, 3*3=9 or 2^2 = 4 3^2 = 9 , but also 2+1^1+0 = 4 or 3+2^2+1 = 9.*

### Method-Specific Principles
* **Everything not adding value to the customer is considered waste** [Lean]
This includes: unnecessary code, unnecessary functionality, delay in progress, unclear requirements, insufficient testing, avoidable process repetition, bureaucracy, slow internal communication, partially done coding, waiting for other activities/team/processes, defects/lower quality, managerial overhead, ...

*Value stream mapping: strategy to recognize waste. Eliminate it iteratively*

* **Amplify learning** [Lean]
  * Run tests as soon as the code is written to prevent accumulation of defects
  * Try different ideas by writing, testing code, and building instead of added documentation or planning
  * Get user input, for example by providing screenshots of the product in development or setting up feedback sessions with customers
  * Enforce short iteration cycles, each including refactoring and integration testing. This maintains a steady supply of feedback as we go

> Multiple design approach [Lean]: assigning the sale problem to different teams, in parallel (*comment: and this is not wasteful!?*)

* **Decide as late as possible** [Lean]
  * Keep decisions pending until they can be made on facts (customer needs/feedback) instead of assuming, as much as possible
  * The more complex a system is, the more if can be able to adapt and change to need
  * Use iterative approaches to adapt to changes and correct mistakes. This reduces cost quite a bit by avoiding to have to correct mistakes after release
  * Planning should be used to concentrate on different options, adapting to the current situation, and clearing up confusions by establishing patterns so they can be adressed quickly and effectively

* **Focus** [Crystal]
In order to ensure continuous progress, focus on an individual task instead of getting scattered amongst multiple tasks.
Avoid interruptions as much as possible when focusing on one task.
Avoid switching projects or (big?) tasks too rapidly (at least 2 days before switching) 

Clearly define and prioritise goals so the project can advance in the asme direction smoothly

* **Deliver as fast as possible** [Lean, SCRUM]
> It is not the biggest that survives, but the fastest. [Poppendieck]

The sooner the end product is delivered, the quicker feed back is received and incorporated in the next iteration.
For software, the Just-In-Time production ideology means presenting the needed result and letting the team organise itself to obtain it in a specific iteration.

> This is not always true, for example VisiCalc opened up the market for spreadsheets only to get dwarfed by bigger companies right after.

* **Minimise dependencies** [SCRUM]
"Scrum asserts that it is possible to remove dependencies between user stories, so that at any point any user story can be selected from a queue according to the proper criteria (maximising business value)"

*In reality, the complexity of a software can easily make it such that the various features are so intricately intertwined that it's difficult to remove anything without everything else crumbling down*

* **Adding features** [*Zave*]
"
In telecommunication software, feature interactions are a notorious source of runaway complexity, bugs, cost and schedule overruns, and unfortunate user experiences.

Bob has "call-forwarding" enabled and is forwarding calls to Carol. Carol has "do-not-disturb".
Alice calls Bob, the call is forwarded to Carol, and Carol's phone rings because "do-not-disturb" is not applied to a forwarded call.

Alice calls a sales group. A feature for the sales group selects Bob as a sales representative on duty, and forwards the call to Bob. Bob's cellphone is off, so his personal Voice Mail answers the call and offers to take a message.

(...more examples...)
"

**Imagined User Stories** [Bertrand Meyer, ETHx course on EDX] corresponding to previous example:
> As an executive, I want a redirection option so that is my hpone is busy the call is redirected to my secretary  
> As a systems configurator, I want to be able to specify various priorities for "busy" actions  
> As a salesperson, I want to make sure that is a prospect calls while I am in a conversation, the conversation is interrupted so that I can take the call immediately  
> As a considerate correspondent, I want to make sure that if a call comes while my phone is busy I get to the option of calling back as soon as the current call is over

* **Personal Safety** [Crystal]
  * Encourage free expression of ideas
  * Do not ridicule anyone because of a question or suggestion
  * Build trust within the team

* **Humanity** [XP]
Recognise that software is developed by people

Offer developers what they expect: saftey, accomplishment, belonging, growth, intimacy

## Roles
### Traditional Manager Roles
* Define goals
* Define deadlines
* Assign tasks
* Provide interface with higher management
* Provide interface with customer
* Validate requirements
* Decide whether goals have been met
* Enfor deadlines
* Coach, mentor
* Enforce rules and methodology
* (...)

> A manager can be a software professional, but also not, for example someone with an MBA and no software knowledge

### The 3 SCRUM Roles
1. (self-organising) team
*group of 7 +/- 2 members*
The team:
* is cross-functional *(one person does not own a whole area, anyone can take on any task)*
* selects iteration(/sprint) goal and work results
* organizes itself and its work
* can do everything within guideline to reach goal
*  demos work results to product owner

> scrums of scrums for bigger projects that need more members

**core participants and fellow travelers**
Core participants are committed to the project; fellow travelers are involved in the project. Fellow travelers stand on the side in discussions and give their opinion if invited to do so.
This is done so meetings are kept focused.

2. Product Owner
*person*
* defines product features
* decides on release date
* decides on release content
* responsible for product profitability (ROI)
* prioritises features according to market value
* can change features and priority over 30 days
* accepts or rejects work results

> is not in charge of individual small sprints

3. Scrum Master
*person*
* ensures that the team is functional and productive
* enables cooperation across all roles and functions
* shields team from external interferences
* enforces process: daily meeting, planning and review meetings
* **removes impediments**
* normally, does no development

> **Impediment**
> Anything that affects the velocity (progress) of the team. [Lean]
>
> Examples:
> * Hardware limitations
> * Missing requirements
> * Missing supporting software (wheter from within or outside of the team)
> * Management interference
> * Bureaucratic delays

*A SCRUM Master can be in several projects if they have the time to if they do not develop.*

**Managers in Agile (if any)**
Agile Managers:
* support team in its use of SCRUM
* contribute wisdom, expertise, and assistance
* Do not "play nanny":
  Assign tasks, get status reports, and other forms of micromanagement
* instead, "play guru":
  Mentor, coach, devil's advocate, help remove impediments, and solve problems
* may need to evolve their management style, *e.g.* use Socratic questioning to help team discover solutions (rather than imposing a solution)

### Other Agile roles
- Expert User [Crystal]
Allows the obtention of actual and accurate needs from actual users
  * Should be an actual user (not just a tester from the development team)
  * Has expert knowledge of the project area
  * Answers questions
  * Suggests solutions to problems
Crystal advises a 2-hour meeting a minimum once per week with the ability to make phone calls

- Customer [XP]
The customer:
  * provides precise stories allowing developers to produce comprehensive task cards and accurate estimates
  * weighs stories against each other and analyzes risk correctly, choosing stories of maximum value for the next iteration
  * trusts developer's technical decisions
  * works within the team in order to quickly provide accurate on-the-go guidance and feedback

- Developer [XP, SCRUM]
**Turns customer stories into working code**

> Frequently asks himself "How to implement it?", "How long will it take?", "What are the risks?

Obligations:
* Works with customer to understand the stories
* Decides implementation from a story
* Estimate work for each story, based on implementation decisions and experience
* Knows and understands technical issues
* Creates and maintains the system as it evolves
* Identify features that depend on other features
* Identify risky features and reports them to customer
* Follows team guidelines
* Implements only what is necessary
* Communicates with customer constantly

Rights (?):
* Estimates own work
* Works sensibly and schedules only work that can be done (so the schedule is predictable)
* Focuses on testing, refactoring, and customer comunication to produce code that meets customer's needs
* Allows the customer to make *business decisions*

- Tracker [XP, SCRUM]
Keeps track of the schedule by monitoring progress and rate of progress in order to determine if the iteration is on schedule. This is done by asking each developer how many tasks they have completed every few days

> Velocity: ratio of ideal time estimated for tasts to actual time spent implementing them

Keeps in mind:
* changes in velocity
* amount of overtime worked
* ratio of passing to failing tests

- Coach [XP]
*Optional role*

The coach:
* guides and mentors the team
* leads by example
* teaches when necessary (even if it's by doing)
* may offer ideas to solve thorny problems
* may serve as intermediary with management

*In SCRUM, this role is absorbed into SCRUM Master.*

## Practices

### Meetings
*model were created for classical teams, could be adapted to distributed teams with modern forms of work (teleworking for example)*

Specific regular "ritual" meetings
* Daily Meeting (most important)
Short (usually 15 minutes), held every working day, should be one of the first things in the work day.
Precise and to-the-point, defines commitments and identify/uncover impediments ("deep" resolutions take place outside of this meeting)
Committed members:
  * What did you do yesterday?
  * What will you do today?
  * Are there any impediments in your way?

* Planning Meeting
Done at the beggining of every sprint (individual iteration)
Goal: define work for the sprint.
Outcome: Sprint Backlog, with time estimate for every task

8-hour time limit (typically one work day):
1st half: product owner + team: prioritize product backlog
2nd half: team only: plan for Sprint, producing sprint backlog

* Retrospective Meeting
*Internal team meeting*
To reflect on past sprint in order to make continuous process improvements
  * What went well?
  * What could be improved?

3-hour time limit

* Review Meeting
To review completed and incomplete work

Present and demo completed work to stakeholders
Incomplete work cannot be demonstrated

4-hour time limit

> Reflective improvement (Crystal)  
> Developers must take breaks from regular development to look for ways to improve the process  
> Iterations help with this by providing feedback on whether or not the current process is working  

### Development


### Release 
Early and often

### Testing and Quality


### Management (and others)


## Artifacts

 
