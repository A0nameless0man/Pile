
```mermaid
classDiagram
class User
class Server
class Record
User : ID
User : Token
User : public exec(cmd)
User : public User(ID,pwd)
User ..> Server : User() login()
Server : private HOST
Server : private map ID,token
Server : private studentList
Server : public token login(ID,pwd)
Server : private string execByHost(cmd,ID,token)
Record : keyNames
Record : keys
```