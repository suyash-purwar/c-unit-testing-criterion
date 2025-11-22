# -*- mode: ruby -*-
# vi: set ft=ruby :

Vagrant.configure("2") do |config|
  config.vm.box = "bento/ubuntu-24.04"
  config.vm.box_version = "202508.03.0"

  config.vm.provider "virtualbox" do |vb|
    vb.memory = "2048"
    vb.cpus = 2
  end

  github_pat = ENV['GITHUB_PAT_FOR_VM']
  github_username = "suyash-purwar"
  repo_name = "c-unit-testing-criterion"

  if github_pat.nil?
    puts "Error: GITHUB_PAT_FOR_VM environment variable not set on host machine."
    puts "Please set it before running 'vagrant up'."
    exit 1
  end

  config.vm.provision "shell", inline: <<-SHELL
    apt-get update
    apt-get install -y build-essential
    apt-get install -y meson cmake

    if [ ! -d "#{repo_name}" ]; then
      echo "Cloning repository..."
      git clone https://oauth2:#{github_pat}@github.com/#{github_username}/#{repo_name}.git
    else
      echo "Repository already exists. Skipping clone."
    fi
  SHELL
end