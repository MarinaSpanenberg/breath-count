function atualizarValor() {
  fetch('/api/data')
    .then(res => res.json())
    .then(data => {
      document.getElementById("value").innerText = data.value;
    });
}

setInterval(atualizarValor, 100);
