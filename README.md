# CPC UNI

Aprendiendo programación competitiva.

## Configuración del Entorno (WSL / Linux)

**Clonar el repositorio:**
Abre tu terminal WSL y clona el proyecto en tu directorio local (`~` recomendado para mayor velocidad).
```bash
git clone https://github.com/AldoLunaBueno/cpc-uni.git
```

**Abrir en VS Code:**
Navega al directorio e inicia el editor (esto instalará el servidor WSL si es la primera vez).
```bash
cd cpc-uni
code .
```

**Nota:** Si WSL no detecta el comando `code`, pero tienes instalado VS Code, busca su ruta en Windows y declara el alias en `~/.bashrc`.

Primero, en el Símbolo del sistema (Windows), obtén la ruta:
```txt
where code
C:\Users\USER\AppData\Local\Programs\Microsoft VS Code\bin\code
```
Luego en WSL (modificando la ruta según lo que obtuviste en el paso anterior):

```bash
echo 'alias code="/mnt/c/Users/USER/AppData/Local/Programs/Microsoft\ VS\ Code/bin/code"' >> ~/.> bashrc
```

**Otorgar permisos de ejecución a los scripts:**
Haz que las herramientas de automatización sean ejecutables por el sistema.
   
```bash
chmod +x ~/cpc-uni/scripts/cinit.sh
chmod +x ~/cpc-uni/scripts/ctest.sh
chmod +x ~/cpc-uni/scripts/crun.sh
```

**Configurar alias globales:**
Inyecta los atajos en tu archivo de configuración de Bash para poder llamarlos desde cualquier subcarpeta del proyecto.
```bash
echo 'alias cinit="~/cpc-uni/scripts/cinit.sh"' >> ~/.bashrc
echo 'alias ctest="~/cpc-uni/scripts/ctest.sh"' >> ~/.bashrc
echo 'alias crun="~/cpc-uni/scripts/crun.sh"' >> ~/.bashrc
```

**Aplicar los cambios:**
Recarga la configuración de tu terminal para que los nuevos comandos estén disponibles inmediatamente.
```bash
source ~/.bashrc
```

## Uso

Estas son las automatizaciones que podemos usar para ganar tiempo.

**Ejecutar:** Compila y ejecuta tu archivo cpp:

```bash
cd 00_repasar_cpp
crun probando.cpp
```

**Inicializar:** Crea un directorio con `main.cpp`, archivos de entrada y salida vacíos para las pruebas y un documento `notes.md` para registrar tus pensamientos rápidamente si lo deseas.

```bash
cd 02_jueces
cinit <tu_problema>
```


**Probar:**  Pone a prueba tu archivo `main.cpp`:

```bash
cd 02_jueces/<tu_problema>
ctest
```