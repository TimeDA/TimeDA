import xlrd
from xlutils.copy import copy
def read_excel():
    xlrdBook = xlrd.open_workbook('results.xls')
    wb = copy(xlrdBook)
    ws = wb.get_sheet(0)
    ws.write(0, 4, label='Non directional')
    tablies = xlrdBook.sheet_by_name('Sheet1')
    count = 0
    for i in range(1, tablies.nrows-1):
        if str(tablies.cell(i,0).value).split('_')[-2] != tablies.cell(i, 2).value :
            count += 1
            ws.write(i, 4, label='1')
        else:
            ws.write(i, 4, label='0')
    ws.write(tablies.nrows-1, 4, label=str(round(count/(tablies.nrows-2), 2)*100)+'%')
    wb.save('result.xls')
if __name__ == '__main__':
    read_excel()

