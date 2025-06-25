# Sistema IoT de monitoramento de RPM (Respirações por minuto)
Este repositório trata-se de um sistema IoT de monitoramento de RPM (Respirações por minuto). Feito utilizando a linguagem de programação **C++** na placa **Arduino Uno R3** e **Python** para comunicação com a placa **Raspberry Pi 4**, que mantém o servidor de uma página simples da web;

## Pré-requisitos

- Placa Arduino Uno R3;
- Arduino IDE;
- Placa Raspberry Pi 4.

## Montagem do circuito:
![circuito](https://github.com/user-attachments/assets/481d9930-85af-4a0e-8981-e99541acadce)

## Execução:
### 1. Crie um ambiente virtual

```bash
python -m venv venv
source env/bin/activate  # No Linux/macOS
env\Scripts\activate     # No Windows
```

2 . Clone o repositório:

```bash
git clone https://github.com/MarinaSpanenberg/breath-count
```

3 . Instale as dependências:
```bash
pip install -r requirements.txt
```

- No Arduino: 
Abra a pasta `breaths_per_minute` no Arduino IDE e clique em compilar.

- Na Rasp:
Execute esse script:
```bash
cd breath-count
cd server
python server.py
```

### Visualização da página web:
Conecte seu PC ou celular na mesma rede de sua Raspberry Pi e pesquise essa linha em um navegador de sua escolha:

```bash
http://RASPBERRY_IP:PORT
```

## Integrantes:
- Ana Flávia Melo;
- João Vítor Bortoluz; 
- Luiz Henrique Albuquerque;
- Marina Barbosa.
