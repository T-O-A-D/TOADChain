from telnetlib import STATUS


class Wallet:
    def __init__(self, credentials):
        self.credentials = credentials

    def getCurrentAmt(self):
      
      return currentMoney

    def getTransaction(self):
      return transaction
      
    def sendMoney(self,value):
      connected = connectToBlockchain(self.uid)
      if connected == True:
        newTransaction(connected,self.uid,value).then((res,err)=>{
          if res.status == "pass":
            return res.status 

        })
      return STATUS

    
id = "goose"
password = "wildgoose"
credentials,login = firebasesignIn(id,password)
if login == "success":
  user = Wallet(credential)


current = Wallet.getCurrentAmt()