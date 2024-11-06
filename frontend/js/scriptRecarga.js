const EmpezarRecarga = document.getElementById("empezarRecarga");
EmpezarRecarga.addEventListener("click", async()=>{
    let Recarga = "recargar"
    postData("EmpezarRecarga", Recarga);
});