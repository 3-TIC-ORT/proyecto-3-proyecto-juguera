function elegidoTamaño(Tamaño){
    postData("opcionesTamaño", Tamaño);
    window.location.href = 'paginaConfirmar.html';
}

document.getElementById("tamaño1").addEventListener("click", function(){
    elegidoTamaño ("Vaso")
})

document.getElementById("tamaño2").addEventListener("click", function(){
    elegidoTamaño ("Jarra")
})
