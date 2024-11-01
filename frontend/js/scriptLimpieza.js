const empezarLimpieza = document.getElementById("empezarLimpieza");
empezarLimpieza.addEventListener("click", async()=>{
    console.log("HOLA FUNCIONO")
    let limpieza = "limpieza"
    postData("EmpezarLimpieza", limpieza);
})