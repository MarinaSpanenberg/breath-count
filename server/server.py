from flask import Flask, render_template, jsonify
import os
import serial
app = Flask(__name__, static_folder="static", template_folder="templates")  

ser = serial.Serial('/dev/ttyACM0', 9600)

IP = os.environ.get('RASPBERRY_IP')
PORT = os.environ.get('RASPBERRY_PORT')

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/api/data')
def get_data():
    try:
        line = ser.readline().decode("UTF-8").strip()
        return jsonify({"value": line})
    except Exception as e:
        return jsonify({"value": "Erro na leitura"})

if __name__ == "__main__":  
    app.run(host=IP, port=PORT)