create unique index PurchaseIndex on Purchase(
  CustomerNumber asc,
  ItemNumber asc,
  OrderTime desc
);