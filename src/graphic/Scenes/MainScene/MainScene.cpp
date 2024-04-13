//
// Created by talleux on 4/10/24.
//

#include "MainScene.hpp"

MainScene::MainScene(Core *core) : AScene(core)
{
    initScene();
}

void MainScene::initScene()
{
    auto vueMeter = std::make_shared<VueMeterComponent>(_core);
    vueMeter->VueMeterComponent::setPosition((sf::Vector2f){100, 600});
    vueMeter->VueMeterComponent::setSize((sf::Vector2f){0.5, 0.5});
    vueMeter->setAttribute("vueMeter1");
    addComponent(vueMeter);

    auto vueMeter2 = std::make_shared<VueMeterComponent>(_core);
    vueMeter2->VueMeterComponent::setPosition((sf::Vector2f){200, 600});
    vueMeter2->VueMeterComponent::setSize((sf::Vector2f){0.5, 0.5});
    vueMeter2->setAttribute("vueMeter2");
    addComponent(vueMeter2);

    auto vueMeter3 = std::make_shared<VueMeterComponent>(_core);
    vueMeter3->VueMeterComponent::setPosition((sf::Vector2f){300, 600});
    vueMeter3->VueMeterComponent::setSize((sf::Vector2f){0.5, 0.5});
    vueMeter3->setAttribute("vueMeter3");
    addComponent(vueMeter3);

    auto vueMeter4 = std::make_shared<VueMeterComponent>(_core);
    vueMeter4->VueMeterComponent::setPosition((sf::Vector2f){1800, 600});
    vueMeter4->VueMeterComponent::setSize((sf::Vector2f){0.5, 0.5});
    vueMeter4->setAttribute("vueMeter4");
    addComponent(vueMeter4);
}

void MainScene::update()
{
    AScene::update();

    for (auto &component : _components)
    {
        if (component->getAttribute() == "vueMeter1")
        {
            auto vueMeter = std::dynamic_pointer_cast<VueMeterComponent>(component);
            float *volume;

            //_core->getAudioEngine()->getInputs()["1"]->getMutex()->lock();

            std::shared_ptr<Buffer> bufferObj = _core->getAudioEngine()->getBuffersPool()->getInputBuffer("1", 1024);

            float *buffer = bufferObj->getBuffer();

            volume = _core->getAudioEngine()->getLevelFromBuffer(buffer, 1024, 2);

            //_core->getAudioEngine()->getInputs()["1"]->getMutex()->unlock();

            volume[0] = volume[0] * 100;
            volume[1] = volume[1] * 100;

            vueMeter->setVolumeValues(volume, 2);
            _core->getAudioEngine()->getInputs()["1"]->setSoundLevel(vueMeter->getVolume());
        }

        if (component->getAttribute() == "vueMeter2")
        {
            auto vueMeter = std::dynamic_pointer_cast<VueMeterComponent>(component);
            float *volume;

            //_core->getAudioEngine()->getInputs()["2"]->getMutex()->lock();

            std::shared_ptr<Buffer> bufferObj = _core->getAudioEngine()->getBuffersPool()->getInputBuffer("2", 1024);

            float *buffer = bufferObj->getBuffer();

            volume = _core->getAudioEngine()->getLevelFromBuffer(buffer, 1024, 2);

            //_core->getAudioEngine()->getInputs()["2"]->getMutex()->unlock();

            volume[0] = volume[0] * 100;
            volume[1] = volume[1] * 100;

            vueMeter->setVolumeValues(volume, 2);
            _core->getAudioEngine()->getInputs()["2"]->setSoundLevel(vueMeter->getVolume());
        }

        if (component->getAttribute() == "vueMeter3")
        {
            auto vueMeter = std::dynamic_pointer_cast<VueMeterComponent>(component);
            float *volume;

            //_core->getAudioEngine()->getInputs()["3"]->getMutex()->lock();

            std::shared_ptr<Buffer> bufferObj = _core->getAudioEngine()->getBuffersPool()->getInputBuffer("3", 1024);

            float *buffer = bufferObj->getBuffer();

            volume = _core->getAudioEngine()->getLevelFromBuffer(buffer, 1024, 2);

            //_core->getAudioEngine()->getInputs()["3"]->getMutex()->unlock();

            volume[0] = volume[0] * 100;
            volume[1] = volume[1] * 100;

            vueMeter->setVolumeValues(volume, 2);
            _core->getAudioEngine()->getInputs()["3"]->setSoundLevel(vueMeter->getVolume());
        }

        if (component->getAttribute() == "vueMeter4")
        {
            auto vueMeter = std::dynamic_pointer_cast<VueMeterComponent>(component);
            float *volume;

            //_core->getAudioEngine()->getInputs()["4"]->getMutex()->lock();

            std::shared_ptr<Buffer> bufferObj = _core->getAudioEngine()->getBuffersPool()->getOutputBuffer("1", 1024);

            float *buffer = bufferObj->getBuffer();

            volume = _core->getAudioEngine()->getLevelFromBuffer(buffer, 1024, 2);

            //_core->getAudioEngine()->getInputs()["4"]->getMutex()->unlock();

            volume[0] = volume[0] * 100;
            volume[1] = volume[1] * 100;

            vueMeter->setVolumeValues(volume, 2);
            _core->getAudioEngine()->getOutputs()["1"]->setSoundLevel(vueMeter->getVolume());
        }
    }

}

void MainScene::handleEvent(const sf::Event &event, sf::RenderWindow &window)
{
    AScene::handleEvent(event, window);
}
