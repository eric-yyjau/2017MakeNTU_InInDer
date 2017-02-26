import pyodbc
server = 'ntusqlserver123.database.windows.net'
database = 'ntu-sqldb'
username = 'ntuserver'
password = 'Ntusql123'
driver= '{ODBC Driver 13 for SQL Server}'
cnxn = pyodbc.connect('DRIVER='+driver+';PORT=1433;SERVER='+server+';PORT=1443;DATABASE='+database+';UID='+username+';PWD='+ password)
cursor = cnxn.cursor()
# cursor.execute("select @@VERSION")
cursor.execute("BEGIN TRANSACTION")
'''
cursor.execute("INSERT SalesLT.Product (Name, ProductNumber, StandardCost, ListPrice, SellStartDate) OUTPUT INSERTED.ProductID VALUES ('SQL Server Express New', 'SQLEXPRESS New', 0, 0, CURRENT_TIMESTAMP)")
cnxn.rollback()
'''

cursor.execute("insert into products(id, name) values ('pyodbc', 'awesome library')")
cnxn.commit()

'''
row = cursor.fetchone()
if row:
    print (row)
'''