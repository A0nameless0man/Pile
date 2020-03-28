CREATE TABLE Customer (
  CustomerNumber char(6) PRIMARY KEY,
  CustomerName char(20) NOT NULL,
  BirthDay datetime,
  Gender char(2),
  City varchar(50),
  Tel char(12),
  Commemt text
);
CREATE TABLE Item(
  ItemNumber char(8) PRIMARY KEY,
  ItemType char(20) NOT NULL,
  ItemName char(50) NOT NULL,
  Price float,
  Manufacturer char(50),
  ShelfLife datetime DEFAULT '2000-1-1',
  Inventory int,
  Comment text
);
CREATE TABLE Purchase(
  CustomerNumber char(6) NOT NULL,
  ItemNumber char(8) NOT NULL,
  OrderTime datetime NOT NULL,
  Count int,
  DueDate datetime,
  Payment varchar(40),
  Delivery varchar(50),
  PRIMARY KEY (CustomerNumber, ItemNumber, OrderTime),
  FOREIGN KEY (CustomerNumber) REFERENCES Customer(CustomerNumber),
  FOREIGN KEY (ItemNumber) REFERENCES Item(ItemNumber)
);
Insert into Item
values
  (
    10010001,
    "Food",
    "Coffee",
    50,
    "YuYiJuice",
    '2013-12-31',
    100,
    NULL
  ),
  (
    10010002,
    "Food",
    "AppleJuice",
    5.2,
    "YuYiJuice",
    '2013-06-08',
    20,
    NULL
  ),
  (
    10020001,
    "Food",
    "Rice",
    35,
    "HealthyFood",
    '2013-12-20',
    100,
    NULL
  ),
  (
    10020002,
    "Food",
    "Flour",
    18,
    "HealthyFood",
    '2013-09-30',
    20,
    NULL
  ),
  (
    20180001,
    "Clothing",
    "Casual",
    120,
    "TTClothes",
    default,
    5,
    "Size not complete"
  ),
  (
    20180002,
    "Clothing",
    "T-shirt",
    50,
    "TTClothes",
    default,
    10,
    NULL
  ),
  (
    30010001,
    "Stationery",
    "Pen",
    3.5,
    "XXStationery",
    default,
    100,
    NULL
  ),
  (
    30010002,
    "Stationery",
    "Clip",
    5.6,
    "XXStationery",
    default,
    50,
    NULL
  ),
  (
    40010001,
    "Book",
    "Menu",
    12,
    "FoodPress",
    default,
    12,
    NULL
  ),
  (
    40010002,
    "Book",
    "How to make soy milk.",
    6,
    "FoodPress",
    default,
    20,
    NULL
  ),
  (
    50020001,
    "Sports",
    "Badminton Racket",
    30,
    "BeautySport",
    default,
    30,
    NULL
  ),
  (
    50020002,
    "Sports",
    "BasketBall",
    80,
    "BeautySport",
    default,
    20,
    NULL
  ),
  (
    50020003,
    "Sports",
    "FootBall",
    65,
    "BeautySport",
    default,
    20,
    NULL
  );
Insert into Customer
values
  (
    100001,
    "ZXL",
    '1979-02-01',
    'Male',
    "JiangSu NanJing",
    "025812345678",
    true,
    "Silver"
  ),
  (
    100002,
    "LHH",
    '1982-03-22',
    'Female',
    "JiangSu SuZhou",
    "13908899120",
    true,
    "Gold"
  ),
  (
    100003,
    "WXM",
    '1976-08-20',
    'Female',
    "ShangHai",
    "02166552101",
    false,
    "NewCustomer"
  ),
  (
    100004,
    "ZM",
    '1972-03-28',
    'Male',
    "HeNan ZhengZou",
    "13809900118",
    false,
    "NewCustomer"
  ),
  (
    100005,
    "ZFY",
    '1980-09-10',
    'Male',
    "ShanDong YanTai",
    "13880933201",
    false,
    NULL
  ),
  (
    100006,
    "WFF",
    '1986-05-01',
    'Female',
    "JiangSu NanJing",
    "13709092011",
    false,
    NULL
  );
Insert into Purchase
values
  (
    100001,
    10010001,
    '2013-02-18 12:20:00',
    2,
    '2013-02-20',
    'Cash',
    'PickUP'
  ),
  (
    100001,
    30010001,
    '2013-02-10 12:30:00',
    10,
    '2013-02-20',
    'Cash',
    'PickUP'
  ),
  (
    100002,
    10010001,
    '2013-02-18 13:00:00',
    default,
    '2013-02-21',
    'Cash',
    'PickUP'
  ),
  (
    100002,
    50020001,
    '2013-02-18 13:20:00',
    default,
    '2013-02-21',
    'Cash',
    'PickUP'
  ),
  (
    100004,
    20180002,
    '2013-02-19 10:00:00',
    default,
    '2013-02-28',
    'Credit',
    'Deliver'
  ),
  (
    100004,
    50020002,
    '2013-02-19 10:40:00',
    2,
    '2013-02-28',
    'Credit',
    'Deliver'
  ),
  (
    100004,
    30010002,
    '2013-02-19 11:00:00',
    10,
    '2013-02-28',
    'Credit',
    'Deliver'
  ),
  (
    100005,
    40010001,
    '2013-02-20 8:00:00',
    2,
    '2013-02-27',
    'Cash',
    'Deliver'
  ),
  (
    100005,
    40010002,
    '2013-02-20 8:20:00',
    3,
    '2013-02-27',
    'Cash',
    'Deliver'
  ),
  (
    100006,
    10020001,
    '2013-02-23 09:00:00',
    5,
    '2013-02-26',
    'Credit',
    'Deliver'
  );