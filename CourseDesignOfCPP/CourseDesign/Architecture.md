```mermaid
sequenceDiagram
    participant C as Client
    participant A as AuthorizeServer
    participant D as DataServer

C->>A:Connect
activate A
alt Is User
    A->>C:Token
    deactivate A
    activate C
else
    A->>C:Refuse
end
loop Working
    C->>A:Commend
    deactivate C
    activate A
    alt Authorized
        A->>D:Command for User
        deactivate A
        activate D
        D->>-A:Result
        activate A
        A->>C:Result
        deactivate A
        activate C
    else not Authorized
        A->>C:Refuse
    end
end
C->>A:DisConnect
deactivate C

```

```SQL
select name , class where sex = male
select name , grade("math") where class = "ComputerScience"
select distinct class where college = "Computer and Software"
insert ("Wang Xuyang" , ...)
insert (name , ...) value ("Wang Xuyang")
set grade("math") = (6,76) where ...
delete where ...#forbid delete without where
```