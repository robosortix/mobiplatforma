
import telebot
import serial
import netifaces as ni

token = 'some_token'

bot = telebot.TeleBot(token)
serport = serial.Serial('/dev/ttyUSB0', 9600, timeout=6)

def get_ip():
    ni.ifaddresses('wlan0')
    ip = ni.ifaddresses('wlan0')[ni.AF_INET][0]['addr']
    return ip

@bot.message_handler(content_types=["text"])
def cmd_process(message):
    print(message.text)
    if message.text == "Get ip":
        buff = get_ip()
        bot.send_message(message.chat.id, buff)
    else:
        serport.write((message.text).encode())
        fin0A = b'\x0A'
        serport.write(fin0A)
        if message.text == "Get th":
            buff = serport.readline().decode("ascii", "ignore")
            bot.send_message(message.chat.id, buff)
        else:
            buff = serport.readline().decode("ascii", "ignore")
            if (buff.find("ok") != -1):
                bot.send_message(message.chat.id, "ok")
            else:
                bot.send_message(message.chat.id, "No answer, timeout!")

def main():
    bot.polling(none_stop=True)

if __name__ == "__main__":
    main()
