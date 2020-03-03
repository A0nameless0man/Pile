# UseCaseDiagram

```puml
scale 0.5
rectangle 系统 as rootSys{
  rectangle 教务管理系统 as jwSys {
    (毕业论文管理) as assertMeg
    (实验室管理) as libMeg
    (学生成绩管理) as greedMeg
    (选修课管理) as seleMeg
    assertMeg .>libMeg
    assertMeg -.>seleMeg
    libMeg - seleMeg
  }
  rectangle 选修课管理子系统 as seleSys{
    (选修课管理) as seleMeg2
    (选修课查询) as seleQue
    (选修课信息汇总) as seleIndex
    (选修课注册) as seleReg
    (教师简历查询) as TechIndex
    seleIndex -u.> seleMeg2
  }
  rectangle 学生成绩管理子系统 as greedSys{
    (学生成绩管理) as greedMeg2
    (学生成绩汇总) as greedSum
    (学生成绩查询) as greedQue
    (课程成绩查询) as CgreedQue
    greedSum -.> greedMeg2
  }
  jwSys .l. seleSys
  jwSys ..u. greedSys
  actor :教学管理员: as techMeger
  libMeg -- techMeger
  seleMeg -- techMeger
  seleMeg2 -- techMeger
  greedMeg -- techMeger
  greedMeg2 -- techMeger
  actor :教务处管理系统: as jw
  greedMeg --> jw
  greedSum -->jw
  actor :教师: as tech
  CgreedQue -- tech
  greedQue -- tech
  seleQue -- tech
  TechIndex -- tech
  actor :学生: as stu
  greedQue -u- stu
  seleQue -u- stu
  seleReg -u- stu
  TechIndex -- stu
  actor :财务: as cw
  seleMeg -- cw
  seleIndex -- cw
}
```
